//
// Created by mac on 2021/6/7.
//
#include "base.h"
#include "Data.h"

int R[MAXN][MAXM];
vector<Client> clients(MAXN);

MatrixXd U(MAXN, MAXK);
MatrixXd V(MAXM, MAXK);

vector<Record> records;
vector<Record> records_test;

double alpha = 0.01;
double eta = 0.01;
int T = 200;
string traindata = "ml-100k/u1.base";
string testdata = "ml-100k/u1.test";
// string traindata, testdata；
string output;

void readConfig(int argc, char *argv[]){
    f(i, 1, argc - 1){
        if(!strcmp(argv[i], "-alpha")) alpha = atof(argv[++ i]);
        else if(!strcmp(argv[i], "-eta")) eta = atof(argv[++ i]);
        else if(!strcmp(argv[i], "-traindata")) traindata = string(argv[++ i]);
        else if(!strcmp(argv[i], "-testdata")) testdata = string(argv[++ i]);
        else if(!strcmp(argv[i], "-output")) output = string(argv[++ i]);
        else if(!strcmp(argv[i], "-T")) T = atoi(argv[++ i]);
    }
    DEBUG(alpha)
    DEBUG(eta)
    DEBUG(traindata)
    DEBUG(testdata)
    DEBUG(output)
    DEBUG(T)
}

void readTrainData(const string& filename){
    ifstream fin(filename);
    int u, i, r, t;
    while(fin >> u >> i >> r >> t){
        R[u][i] = r;
        clients[u].I_u.insert(i);
        records.push_back({u, i, r});
    }

    fin.close();
}
void readTestData(const string& filename){
    ifstream fin(filename);
    int u, i, r, t;
    while(fin >> u >> i >> r >> t){
        records_test.push_back({u, i, r});
    }

    fin.close();
}
void initParam(){
    srand(time(0));

    f(i, 0, U.rows() - 1){
        f(j, 0, U.cols() - 1){
            U(i, j) = ((double)rand() / RAND_MAX - 0.5) * 0.01;
        }
    }

    f(i, 0, V.rows() - 1){
        f(j, 0, V.cols() - 1){
            V(i, j) = ((double)rand() / RAND_MAX - 0.5) * 0.01;
        }
    }

}
