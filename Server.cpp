#include "Server.h"

void Server::train() {
    random_shuffle(records.begin(), records.end());
    f(iter, 1, T){
        for(auto record: records){
            int u = record.u;
            int i = record.i;
            int r = record.r;
            VectorXd grad_u(MAXK), grad_v(MAXK);
            update(u, i, r, grad_u, grad_v);
        }
        eta = eta * 0.95;
        if(iter % 20 == 0){
            evaluate(iter);
        }
    }
}

void Server::update(int u, int i, int r, VectorXd& grad_u, VectorXd& grad_v) {
    VectorXd U_u = U.row(u);
    VectorXd V_i = V.row(i);
    double e = 1.0 * r - predict(u, i);
    grad_u = -e * V_i + alpha * U_u;
    grad_v = -e * U_u + alpha * V_i;

    U.row(u) -= eta * grad_u;
    V.row(i) -= eta * grad_v;

}

void Server::evaluate(int iter) {
    double MSE = 0, MAE = 0;
    for(auto record: records_test){
        int u = record.u;
        int i = record.i;
        int r = record.r;
        double r_hat = predict(u, i);
        MSE += (r - r_hat) * (r - r_hat);
        MAE += fabs(r - r_hat);
    }
    MSE = sqrt(MSE / records_test.size());
    MAE = MAE / records_test.size();
    PRINT(os, iter)
    PRINT(os, MSE)
    PRINT(os, MAE)
    CSV(os_csv, iter, MSE, MAE)
}

double Server::predict(int u, int i){
    VectorXd U_u = U.row(u);
    VectorXd V_i = V.row(i);
    return (U_u.transpose() * V_i)(0);
}
