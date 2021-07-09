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
    static void evaluate();

private:
    static void update(int u, int i, int r, VectorXd& grad_u, VectorXd& grad_v);
    static double predict(int u, int i);

};

#endif //RS_SERVER_H
