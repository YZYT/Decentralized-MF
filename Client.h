//
// Created by mac on 2021/6/7.
//

#ifndef RS_CLIENT_H
#define RS_CLIENT_H

#include "Base.h"

using namespace std;


class Client {
    friend class Builder;
private:
    VectorXd                        U_u;
    MatrixXd                        V;
    double                          eta_u;
    double                          eta_v;
    set<Interaction>                I_u;
    set<Interaction>                I_u_test;
    vector<Edge>                    neighbours;
    Grads_neigh                     neigh_grads_v[MAXM];

    vector<VectorXd*>               pool;

    void update(iid i, rating r, VectorXd* grad_u, VectorXd* grad_v);
    void receive_grad(iid i, VectorXd* grad_v);
    rating predict(iid i);

public:
    Client(){
        U_u = VectorXd(MAXK);
        V = MatrixXd(MAXM, MAXK);
        eta_u = 0.01;
        eta_v = 0.01;
    };
    void initial();
    void initParam(VectorXd& V_i);
    void rate(iid i, rating r);
    void rate_test(iid i, rating r);
    void train();
    void reach_consensus();
    metrics evaluate_local();
    metrics evaluate_global();
    metrics evaluate_self();
    void print();
};


#endif //RS_CLIENT_H
