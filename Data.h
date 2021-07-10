//
// Created by mac on 2021/6/7.
//

#ifndef RS_DATA_H
#define RS_DATA_H

#include <string>
#include <vector>
#include <Eigen/Dense>
#include "Client.h"

using namespace std;
using namespace Eigen;

const int MAXN = 1e3 + 5, MAXM = 2e3 + 5, MAXK = 40;


extern rating R[MAXN][MAXM];
extern vector<Client> clients;
struct Record{
    uid     u;
    iid     i;
    rating  r;
};
extern vector<Record> records;
extern vector<Record> records_test;

extern MatrixXd U;
extern MatrixXd V;

extern double alpha;
extern double eta;
extern int T;
extern string traindata, testdata, output;

void readConfig(int argc, char *argv[]);
void readTrainData(const string& filename);
void readTestData(const string& filename);
void initParam();

#endif //RS_DATA_H
