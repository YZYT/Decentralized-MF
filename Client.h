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
    };
    void initial();
    void initParam();
    void rate(iid i, rating r);
    void rate_test(iid i, rating r);
    void train();
    void reach_consensus();
    metrics evaluate_local();
    metrics evaluate_global();
    metrics evaluate_self();
};


#endif //RS_CLIENT_H
