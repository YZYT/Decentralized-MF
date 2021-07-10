#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double>    PDD;
typedef PDD                     metrics;   /* (MSE, MAE) */

int COPY[] = {1, 2, 3, 4, 5};
// double ALPHA[] = {0.01};
double ALPHA[] = {0.1, 0.01, 0.001};
// double ETA[] = {0.01};
double ETA[] = {0.1, 0.05, 0.01};
char buffer[1000];

struct Node{
    double alpha, eta;
    double MSE, MAE;
    bool operator < (Node& tmp){
        return MSE < tmp.MSE;
    }
};
vector<Node> pool;

metrics exec(int copy, double alpha, double eta){
    sprintf(buffer, "./build/RS -traindata ML100K/ML100K_copy%d_train.txt -testdata ML100K/ML100K_copy%d_valid.txt -output copy%d_valid -T 300 -alpha %f -eta %f", copy, copy, copy, alpha, eta);
    system(buffer);

    sprintf(buffer, "../results/copy%d_valid.tmp", copy);
    ifstream is(buffer);
    metrics m;
    is >> m.first >> m.second;
    return m;
}

Node calc(double alpha, double eta){
    Node res;
    res.alpha = alpha;
    res.eta = eta;
    res.MSE = res.MAE = 0;
    for(auto copy: COPY){
        metrics tmp = exec(copy, alpha, eta);
        res.MSE += tmp.first;
        res.MAE += tmp.second;
    }
    return res;
}

int main(int argc, char *argv[]){
    for(auto alpha: ALPHA){
        for(auto eta: ETA){
            pool.push_back(calc(alpha, eta));
        }
    }
    for(auto node: pool){
        cout << node.MSE << " " << node.MAE << endl;
    }
}