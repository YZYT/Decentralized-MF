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
    static void performance();

private:
    static void update(uid u, iid i, rating r, VectorXd& grad_u, VectorXd& grad_v);
    static rating predict(uid u, iid i);

};

#endif //RS_SERVER_H
