//
// Created by mac on 2021/6/7.
//

#include "Client.h"

void Client::initParam(){
    
    f(i, 0, (int)U_u.rows() - 1){
        U_u(i) = ((double)rand() / RAND_MAX - 0.5) * 0.01;
    }
    
    f(i, 0, (int)V.rows() - 1){
        f(j, 0, (int)V.cols() - 1){
            V(i, j) = ((double)rand() / RAND_MAX - 0.5) * 0.01;
        }
    }
}

void Client::initParam_U(VectorXd& _U_u){
    U_u = _U_u;
}
void Client::initParam_V(MatrixXd& _V){
    V = _V;
}

void Client::rate(iid i, rating r){
    I_u.push_back({i, r});
}

void Client::rate_test(iid i, rating r){
    I_u_test.push_back({i, r});
}

void Client::init_recv(){
    neigh_grads_v = new Grads_neigh[MAXM];
}

void Client::init_train(){
    random_shuffle(I_u.begin(), I_u.end());
    next_ix = 0;
}

bool Client::train_next(){

    if(next_ix >= I_u.size()) return false;

    iid i = I_u[next_ix].i;
    rating r = I_u[next_ix ++].r;


    VectorXd* grad_u = new VectorXd(MAXK);
    VectorXd* grad_v = new VectorXd(MAXK);

    update(i, r, grad_u, grad_v);
    
    for(auto& edge: neighbours){
        Client* neighbour = edge.neighbour;
        neighbour->receive_grad(i, grad_v, edge);
    }

    // pool.push_back(grad_v);
    delete grad_u;
    delete grad_v;
    return true;
}

void Client::reach_consensus(){

    f(i, 0, MAXM - 1){

        VectorXd* neigh_grad_v = neigh_grads_v[i].grad;
        if(!neigh_grad_v) continue;

        V.row(i) -= eta * *neigh_grad_v / neigh_grads_v[i].cnt;

        delete neigh_grad_v;
        neigh_grads_v[i].grad = 0;

    }
    delete[] neigh_grads_v;


}

void Client::update(iid i, rating r, VectorXd* grad_u, VectorXd* grad_v) {
    VectorXd V_i = V.row(i);
    rating e = 1.0 * r - predict(i);
    *grad_u = -e * V_i + alpha * U_u;
    *grad_v = -e * U_u + alpha * V_i;

    U_u -= eta * *grad_u;
    V.row(i) -= eta * *grad_v;
}

void Client::receive_grad(iid i, VectorXd* grad_v, Edge& edge){
    assert(i < MAXM);
    neigh_grads_v[i].update(grad_v, edge, i);
    // V.row(i) -= eta * *grad_v;
}

rating Client::predict(iid i){
    VectorXd V_i = V.row(i);
    return (U_u.transpose() * V_i)(0);
}

metrics Client::evaluate_local() {
    rating MSE = 0, MAE = 0;
    for(auto ix: I_u_test){
        iid i = ix.i;
        rating r = ix.r;
        rating r_hat = predict(i);
        if(r_hat < 1) r_hat = 1;
        if(r_hat > 5) r_hat = 5;
        MSE += (r - r_hat) * (r - r_hat);
        MAE += fabs(r - r_hat);
    } 
    MSE = sqrt(MSE / I_u_test.size());
    MAE = MAE / I_u_test.size();
    return metrics(MSE, MAE);
}

metrics Client::evaluate_global() {
    rating MSE = 0, MAE = 0;
    for(auto ix: I_u_test){
        iid i = ix.i;
        rating r = ix.r;
        rating r_hat = predict(i);
        if(r_hat < 1) r_hat = 1;
        if(r_hat > 5) r_hat = 5;
        MSE += (r - r_hat) * (r - r_hat);
        MAE += fabs(r - r_hat);
    }
    return metrics(MSE, MAE);
}


metrics Client::evaluate_self() {
    rating MSE = 0, MAE = 0;
    for(auto ix: I_u){
        iid i = ix.i;
        rating r = ix.r;
        rating r_hat = predict(i);
        if(r_hat < 1) r_hat = 1;
        if(r_hat > 5) r_hat = 5;
        MSE += (r - r_hat) * (r - r_hat);
        MAE += fabs(r - r_hat);
    }
    return metrics(MSE, MAE);
}


void Client::print() {
    CERR(U_u)
    CERR(V.row(2))
    // int t = 10;
    // for(auto ix: I_u_test){
    //     t --;
    //     if(t < 0) break;
    //     iid i = ix.i;
    //     rating r = ix.r;
    //     rating r_hat = predict(i);
    //     CERR(r)
    //     CERR(r_hat)
    // }
}