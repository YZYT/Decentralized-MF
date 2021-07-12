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
class Client;
typedef pair<Client*, double>   Edge;

typedef pair<iid, VectorXd*>     package;


template<class T1, class T2> 
inline const pair<T1, T2> operator + (const pair<T1, T2>& p1, const pair<T1, T2>& p2)
{
    pair<T1, T2> res;
    res.first = p1.first + p2.first;
    res.second = p1.second + p2.second;
    return res;
}


template<class T1, class T2>
inline const pair<T1, T2> operator - (const pair<T1, T2>& p1, const pair<T1, T2>& p2)
{
    pair<T1, T2> res;
    res.first = p1.first - p2.first;
    res.second = p1.second - p2.second;
    return res;
}


struct Interaction{
    iid     i;
    rating  r;
    bool operator = (const Interaction& tmp)const{
        return i == tmp.i;
    }
    bool operator < (const Interaction& tmp)const{
        return i < tmp.i;
    }
    bool operator > (const Interaction& tmp)const{
        return i > tmp.i;
    }
};

class Grads_neigh{
public:
    int cnt;
    VectorXd* grad;
    Grads_neigh(){
        grad = 0;
    }
    ~Grads_neigh(){
        if(grad) delete grad;
    }
    void update(VectorXd *_grad){
        if(!grad){
            cnt = 1;
            grad = new VectorXd(*_grad);
        }
        else{
            *grad += *_grad;
            cnt ++;
        }
    }
};


struct Record{
    uid     u;
    iid     i;
    rating  r;
};

extern string traindata;
extern string testdata;
extern string output;

extern ofstream os;
extern ofstream os_tmp;
extern ofstream os_csv;

extern double alpha;
extern double eta;
extern int T;

// extern const int MAXN;
// extern const int MAXM;
// extern const int MAXK;


const int MAXN = 1e3 + 5;
const int MAXM = 2e3 + 5;
const int MAXK = 20;

extern vector<Record> records_test;

#endif //RS_BASE_H