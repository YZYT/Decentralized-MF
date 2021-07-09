//
// Created by mac on 2021/6/7.
//

#ifndef RS_CLIENT_H
#define RS_CLIENT_H

#include "base.h"

using namespace std;


class Client {
    friend void readTrainData(const string& filename);
    set<int> I_u;
public:
    Client()= default;
};


#endif //RS_CLIENT_H
