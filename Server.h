//
// Created by mac on 2021/6/7.
//

#ifndef RS_SERVER_H
#define RS_SERVER_H

#include "Base.h"
#include "Data.h"
#include "Client.h"

class Server {
    friend class Builder;
public:
    Server(){
        clients.resize(MAXN);
    }
    void initParam();
    void train();
    metrics evaluate();
    void performance();
    vector<Client> clients;
private:


};

#endif //RS_SERVER_H
