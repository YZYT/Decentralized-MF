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

const int MAXN = 1e3 + 5, MAXM = 2e3 + 5, MAXK = 3;


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
extern MatrixXd P;
extern MatrixXd Q;

extern float alpha;
extern float eta;
extern float eta_initial;
extern int early_stop;
extern int T;
extern string traindata, testdata, output;

extern float average_rating[MAXN];
extern float average_rating_item[MAXM];
extern int active[MAXN];
extern int active_item[MAXM];

extern vector<float> loss_record_train;
extern vector<float> loss_record_dev;


void readConfig(int argc, char *argv[]);
void readTrainData(const string& filename);
void readTestData(const string& filename);
void initParam();
void saveModel();
void save_learning_curve();

#endif //RS_DATA_H
