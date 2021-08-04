//
// Created by mac on 2021/7/7.
//

#ifndef RS_BASE_H
#define RS_BASE_H
#include <iostream>
#include <thread>
#include <mutex>
#include <Eigen/Dense>
#include <ctime>
#include <fstream>
#include <set>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <utility>
#include <filesystem>


#define f(i,l,r) for(int i=(l);i<=(r);i++)
#define CERR(x) cout << #x << " : " << x << endl;
#define COUT(os,x) os << #x << " : " << x << endl;
#define PRINT(os,x) CERR(x) COUT(os,x) 
#define CSV(os,a,b,c) os << a << "," << b << "," << c << endl;
#define getMSE(m)   m.first
#define getMAE(m)   m.second

using namespace Eigen;
using namespace std;

typedef pair<double, double>    PDD;
typedef PDD                     metrics;   /* (MSE, MAE) */
typedef double                  rating;
typedef int                     uid;       /* user id */
typedef int                     iid;       /* item id */



extern ofstream os;
extern ofstream os_tmp;
extern ofstream os_csv;

extern ofstream os_debug_csv;
#endif //RS_BASE_H
