#include "Server.h"


void Server::initParam(){
    srand(233);
    VectorXd U_u(MAXK);
    int cnt = 0;
    for(auto& client: clients){
        f(i, 0, U_u.rows() - 1){
            U_u(i) = ((double)rand() / RAND_MAX - 0.5) * 0.01;
            cnt ++;
        }
        client.initParam_U(U_u);
    }


    MatrixXd V(MAXM, MAXK);
    f(i, 0, V.rows() - 1){
        f(j, 0, V.cols() - 1){
            V(i, j) = ((double)rand() / RAND_MAX - 0.5) * 0.01;
        }
    }
    for(auto& client: clients){
        client.initParam_V(V);
    }
    
    // for(auto& client: clients){
    //     client.initParam();
    // }

}

void Server::train() {
    // random_shuffle(records.begin(), records.end());

    f(iter, 1, T * 5){
        CERR(iter)

        for(auto& client: clients){
            client.train();
        }
        // assert(1 == 0);

        // for(auto& client: clients){
        //     client.reach_consensus();
        // }
        
        eta = eta * 0.9;
        
        // f(i, 1, 3){
        //     int x = rand() % 500 + 1;
        //     clients[x].print();
        // }
        if(iter % 1 == 0 && iter > 3){
            metrics tmp(0, 0);
            for(auto& client: clients){
                tmp = tmp + client.evaluate_global();
            }

            rating MSE = getMSE(tmp) / records_test.size();
            rating MAE = getMAE(tmp) / records_test.size();

            PRINT(os, iter)
            PRINT(os, MSE)
            PRINT(os, MAE)
            CSV(os_csv, iter, MSE, MAE)
        }
    }
}

// void Server::performance() {
//     metrics m = evaluate();
//     os_tmp << getMSE(m) << " " << getMAE(m) << endl;
// }