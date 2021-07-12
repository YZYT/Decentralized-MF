//
// Created by mac on 2021/6/7.
//

#include "Client.h"

void Client::initParam(){
    
    f(i, 0, (int)U_u.cols() - 1){
        U_u(i) = ((double)rand() / RAND_MAX - 0.5) * 0.01;
    }
    
    f(i, 0, (int)V.rows() - 1){
        f(j, 0, (int)V.cols() - 1){
            V(i, j) = ((double)rand() / RAND_MAX - 0.5) * 0.01;
        }
    }
}

void Client::rate(iid i, rating r){
    I_u.insert({i, r});
}

void Client::rate_test(iid i, rating r){
    I_u_test.insert({i, r});
}

void Client::initial(){
    for(auto t: pool){
        delete t;
    }
    pool.clear();

    // neigh_grads_v.clear();
}

void Client::train(){
    initial();

    for(auto ix: I_u){
        iid i = ix.i;
        rating r = ix.r;
        VectorXd* grad_u = new VectorXd(MAXK);
        VectorXd* grad_v = new VectorXd(MAXK);
        update(i, r, grad_u, grad_v); 
        
        for(auto edge: neighbours){
            Client* neighbour = edge.first;
            neighbour->receive_grad(i, grad_v);
        }

        pool.push_back(grad_v);
        delete grad_u;
    }
}

void Client::reach_consensus(){

    // VectorXd grad_v(MAXK);
    // cout << grad_v << endl;
    // CERR(neigh_grads_v.size())
    // cout << "QQQQ" << endl;
    f(i, 0, MAXM - 1){

        VectorXd* neigh_grad_v = neigh_grads_v[i].grad;
        if(!neigh_grad_v) continue;
        // assert(V.row(i).size() == neigh_grad_v->size());
        // cout << i << endl;
        V.row(i) -= eta * *neigh_grad_v;

        delete neigh_grad_v;
        neigh_grads_v[i].grad = 0;
        // grad_v += *neigh_grad_v;
        // cout << "QQ" << endl;
    }

    // cout << grad_v << endl;
}

void Client::update(iid i, rating r, VectorXd* grad_u, VectorXd* grad_v) {
    VectorXd V_i = V.row(i);
    rating e = 1.0 * r - predict(i);
    *grad_u = -e * V_i + alpha * U_u;
    *grad_v = -e * U_u + alpha * V_i;

    U_u -= eta * *grad_u;
    V.row(i) -= eta * *grad_v;
}

void Client::receive_grad(iid i, VectorXd* grad_v){
    neigh_grads_v[i].update(grad_v);
    // neigh_grads_v.push_back(i);
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
        // CERR(r)
        // CERR(r_hat)
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
        // CERR(r)
        // CERR(r_hat)
        MSE += (r - r_hat) * (r - r_hat);
        MAE += fabs(r - r_hat);
    }
    return metrics(MSE, MAE);
}