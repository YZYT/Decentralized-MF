#include "Base.h"


ofstream os;
ofstream os_tmp;
ofstream os_csv;

// string traindata = "../ml-100k/u1.base";
string traindata = "../data/ML100K/ML100K_copy1_train.txt";
// string testdata = "../ml-100k/u1.test";
string testdata = "../data/ML100K/ML100K_copy1_test.txt";

string output;

double alpha = 0.001;
double eta = 0.03;
int T = 200;

vector<Record> records_test;
vector<Record> records;

int DEBUGS = 0;
int DEBUGS2 = 0;