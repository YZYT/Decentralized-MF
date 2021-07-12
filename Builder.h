
#ifndef RS_BUILDER_H
#define RS_BUILDER_H

#include "Base.h"
#include "Client.h"
#include "Server.h"

using namespace std;


class Builder {
public:
    Builder()=default;
    Builder(int argc, char *argv[]);
    ~Builder(){};
    Server* build(int argc, char *argv[]);

private:
    // double W[MAXN][MAXN];
    Server* server;

    void readConfig(int argc, char *argv[]);
    void readTrainData(const string& filename);
    void readTestData(const string& filename);
    void buildGraph();
    double calcSimilarity(Client& u, Client& v);
};



#endif //RS_BUILDER_H