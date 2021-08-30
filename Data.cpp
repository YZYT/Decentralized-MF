//
// Created by mac on 2021/6/7.
//
#include "base.h"
#include "Data.h"

rating R[MAXN][MAXM];
vector<Client> clients(MAXN);

MatrixXd U(MAXN, MAXK);
MatrixXd P(MAXM, 4);
MatrixXd Q(4, 20);

float average_rating[MAXN];
int active[MAXN];


float average_rating_item[MAXM];
int active_item[MAXM];

vector<float> loss_record_train;
vector<float> loss_record_dev;

vector<Record> records;
vector<Record> records_test;

float alpha = 0;
float eta = 0.0001;
float eta_initial = eta;
int early_stop = 100;

int T = 200;
string traindata = "data/ML100K/ML100K_copy1_train.txt";
// string traindata = "../data/ML100K/ML100K_copy1_train.txt";
string testdata = "data/ML100K/ML100K_copy1_test.txt";
// string testdata = "../data/ML100K/ML100K_copy1_valid.txt";

string output;
char outpath[200];

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
            U(i, j) = ((float)rand() / RAND_MAX) * 0.01;
        }
    }


    f(i, 0, (int)P.rows() - 1){
        f(j, 0, (int)P.cols() - 1){
            P(i, j) = ((float)rand() / RAND_MAX) * 0.01;
        }
    }

    f(i, 0, (int)Q.rows() - 1){
        f(j, 0, (int)Q.cols() - 1){
            Q(i, j) = ((float)rand() / RAND_MAX) * 0.01;
        }
    }

}

void saveModel(){
    sprintf(outpath, "model/model_al%.3f_et%.3f.out", alpha, eta_initial);
    ofstream os(outpath);
    f(i, 0, (int)U.rows() - 1){
        f(j, 0, (int)U.cols() - 1){
            if(j) os << " ";
            os << U(i, j);
        }
        os << endl;
    }
    // f(i, 0, (int)V.rows() - 1){
    //     f(j, 0, (int)V.cols() - 1){
    //         if(j) os << " ";
    //         os << V(i, j);
    //     }
    //     os << endl;
    // }
    os.close();
}

void save_learning_curve(){
    sprintf(outpath, "model/lc_al%.3f_et%.3f.csv", alpha, eta_initial);
    ofstream os(outpath);
    os << "iter,loss_dev,loss_train" << endl;
    f(i, 0, (int)loss_record_dev.size() - 1){
        os << i << "," << loss_record_dev[i] << "," << loss_record_train[i] << endl;
    }
}