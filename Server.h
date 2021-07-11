//
// Created by mac on 2021/6/7.
//

#ifndef RS_SERVER_H
#define RS_SERVER_H

#include "Base.h"
#include "Data.h"

class Server {
public:
    Server()=default;
    void train();
    metrics evaluate();
    void performance();

private:
    void update(uid u, iid i, rating r, VectorXd& grad_u, VectorXd& grad_v);
    rating predict(uid u, iid i);

};

#endif //RS_SERVER_H
