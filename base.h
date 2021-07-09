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
#include <filesystem>


#define f(i,l,r) for(int i=(l);i<=(r);i++)
#define CERR(x) cout << #x << " : " << x << endl;
#define COUT(os,x) os << #x << " : " << x << endl;
#define PRINT(os,x) CERR(x) COUT(os,x) 
#define CSV(os,a,b,c) os << a << "," << b << "," << c << endl;

using namespace Eigen;
using namespace std;

extern ofstream os;
extern ofstream os_csv;
#endif //RS_BASE_H
