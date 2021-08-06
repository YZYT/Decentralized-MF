//
// Created by mac on 2021/6/7.
//

#ifndef RS_SERVER_H
#define RS_SERVER_H

#include "base.h"
#include "Data.h"

class Server {
public:
    static void train();
    static metrics evaluate();
    static float evaluate_loss();
    static metrics evaluate_local();
    static void performance();
    static void printU();

private:
    static void update(uid u, iid i, rating r, VectorXd& grad_u, VectorXd& grad_v, MatrixXd& grad_q);
    static rating predict(uid u, iid i);

};

#endif //RS_SERVER_H
