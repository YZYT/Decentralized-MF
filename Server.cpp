#include "Server.h"

void Server::train() {

    f(iter, 1, 10){
        for(auto record: records){
            uid u = record.u;
            iid i = record.i;
            rating r = record.r;
            VectorXd grad_u(MAXK), grad_v(MAXK);
            update(u, i, r, grad_u, grad_v);
        }
        eta = eta * 0.95;
        if(iter % 10 == 0){
            metrics tmp = evaluate();
            rating MSE = getMSE(tmp);
            rating MAE = getMAE(tmp);
            PRINT(os, iter)
            PRINT(os, MSE)
            PRINT(os, MAE)
            CSV(os_csv, iter, MSE, MAE)
        }
    }
    // f(i, 1, 10){
    //     int a = rand() % 500 + 1;
    //     CERR(U.row(a))
    // }
    // f(i, 1, 10){
    //     int a = rand() % 500 + 1;
    //     CERR(V.row(a))
    // }
}

void Server::update(uid u, iid i, rating r, VectorXd& grad_u, VectorXd& grad_v) {
    VectorXd U_u = U.row(u);
    VectorXd V_i = V.row(i);
    rating e = 1.0 * r - predict(u, i);
    grad_u = -e * V_i + alpha * U_u;
    grad_v = -e * U_u + alpha * V_i;

    U.row(u) -= eta * grad_u;
    V.row(i) -= eta * grad_v;
}

metrics Server::evaluate() {
    rating MSE = 0, MAE = 0;
    for(auto record: records_test){
        uid u = record.u;
        iid i = record.i;
        rating r = record.r;
        rating r_hat = predict(u, i);
        MSE += (r - r_hat) * (r - r_hat);
        MAE += fabs(r - r_hat);
    }
    MSE = sqrt(MSE / records_test.size());
    MAE = MAE / records_test.size();
    return metrics(MSE, MAE);
}

rating Server::predict(uid u, iid i){
    VectorXd U_u = U.row(u);
    VectorXd V_i = V.row(i);
    return (U_u.transpose() * V_i)(0);
}

void Server::performance() {
    metrics m = evaluate();
    os_tmp << getMSE(m) << " " << getMAE(m) << endl;
}