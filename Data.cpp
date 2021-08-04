//
// Created by mac on 2021/6/7.
//
#include "base.h"
#include "Data.h"

rating R[MAXN][MAXM];
vector<Client> clients(MAXN);

MatrixXd U(MAXN, MAXK);
MatrixXd V(MAXM, MAXK);

float average_rating[MAXN];
int active[MAXN];


float average_rating_item[MAXM];
int active_item[MAXM];



vector<Record> records;
vector<Record> records_test;

double alpha = 0;
double eta = 0.05;
int T = 200;
string traindata = "data/ML100K/ML100K_copy1_train.txt";
// string traindata = "../data/ML100K/ML100K_copy1_train.txt";
string testdata = "data/ML100K/ML100K_copy1_test.txt";
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

    os_debug_csv.open("results/U_u_k=1.csv");

    PRINT(os, alpha)
    PRINT(os, eta)
    PRINT(os, traindata)
    PRINT(os, testdata)
    PRINT(os, output)
    PRINT(os, T)

    CSV(os_csv, "iter", "MSE", "MAE")
    CSV(os_debug_csv, "norm", "average_rating", "ative")
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

        active[u] ++;
        active_item[i] ++;

        average_rating[u] += r;
        average_rating_item[i] += r;
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

    f(i, 0, (int)U.rows() - 1){
        f(j, 0, (int)U.cols() - 1){
            U(i, j) = ((double)rand() / RAND_MAX - 0.5) * 0.01;
        }
    }


    f(i, 0, (int)V.rows() - 1){
        f(j, 0, (int)V.cols() - 1){
            V(i, j) = ((double)rand() / RAND_MAX - 0.5) * 0.01;
        }
    }

}
