//
// Created by mac on 2021/6/7.
//
#include "base.h"
#include "Data.h"

rating R[MAXN][MAXM];
vector<Client> clients(MAXN);

MatrixXd U(MAXN, MAXK);
MatrixXd V(MAXM, MAXK);

vector<Record> records;
vector<Record> records_test;

double alpha = 0.01;
double eta = 0.01;
int T = 200;
string traindata = "../ml-100k/u1.base";
// string traindata = "../data/ML100K/ML100K_copy1_train.txt";
string testdata = "../ml-100k/u1.test";
// string testdata = "../data/ML100K/ML100K_copy1_valid.txt";

string output;

void readConfig(int argc, char *argv[]){
    f(i, 1, argc - 1){
        if(!strcmp(argv[i], "-alpha")) alpha = atof(argv[++ i]);
        else if(!strcmp(argv[i], "-eta")) eta = atof(argv[++ i]);
        else if(!strcmp(argv[i], "-traindata")) traindata = "../data/" + string(argv[++ i]);
        else if(!strcmp(argv[i], "-testdata")) testdata = "../data/" + string(argv[++ i]);
        else if(!strcmp(argv[i], "-output")){
            output = "../results/" + string(argv[++ i]);
            os.open(output + ".out");
            os_tmp.open(output + ".tmp");
            os_csv.open(output + ".csv");
        }
        else if(!strcmp(argv[i], "-T")) T = atoi(argv[++ i]);
    }
    PRINT(os, alpha)
    PRINT(os, eta)
    PRINT(os, traindata)
    PRINT(os, testdata)
    PRINT(os, output)
    PRINT(os, T)

    CSV(os_csv, "iter", "MSE", "MAE")
}

void readTrainData(const string& filename){
    ifstream fin(filename);
    uid u;
    iid i;
    rating r;
    string t;
    cout << filename << endl;
    while(fin >> u >> i >> r >> t){
        R[u][i] = r;
        clients[u].I_u.insert(i);
        records.push_back({u, i, r});
    }
    fin.close();
}
void readTestData(const string& filename){
    ifstream fin(filename);
    uid u;
    iid i;
    rating r;
    string t;
    while(fin >> u >> i >> r >> t){
        records_test.push_back({u, i, r});
    }

    fin.close();
}
void initParam(){
    srand(233);
    int cnt = 0;
    f(i, 0, (int)U.rows() - 1){
        f(j, 0, (int)U.cols() - 1){
            U(i, j) = ((double)rand() / RAND_MAX - 0.5) * 0.01;
            cnt ++;
        }
    }
    CERR(U.row(3))

    cout << cnt << endl;

    f(i, 0, (int)V.rows() - 1){
        f(j, 0, (int)V.cols() - 1){
            V(i, j) = ((double)rand() / RAND_MAX - 0.5) * 0.01;
        }
    }
    CERR(V.row(2))
    assert(1 == 0);
}
