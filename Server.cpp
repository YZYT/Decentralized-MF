#include "Server.h"


void Server::initParam(){
    srand(233);
    // VectorXd U_u(MAXK);
    // int cnt = 0;
    // for(auto& client: clients){
    //     f(i, 0, U_u.rows() - 1){
    //         U_u(i) = ((double)rand() / RAND_MAX - 0.5) * 0.01;
    //         cnt ++;
    //     }
    //     client.initParam_U(U_u);
    // }


    // MatrixXd V(MAXM, MAXK);
    // f(i, 0, V.rows() - 1){
    //     f(j, 0, V.cols() - 1){
    //         V(i, j) = ((double)rand() / RAND_MAX - 0.5) * 0.01;
    //     }
    // }
    // for(auto& client: clients){
    //     client.initParam_V(V);
    // }
    
    for(auto& client: clients){
        client.initParam();
    }

}

void Server::train() {
    random_shuffle(records.begin(), records.end());
    
    f(iter, 1, 40){
        if(iter > 20){
            int x;
            cin >> x;
            if(x != 1) break;
        }
        CERR(iter)

        for(auto& client: clients){
            client.init_train();
        }

        bool next_round = true;
        
        while(next_round){
            for(auto& client: clients){
                client.init_recv();
            }

            next_round = false;

            for(auto& client: clients){
                if(client.train_next(next_round)){
                    next_round = true;
                }
            }

            for(auto& client: clients){
                client.reach_consensus();
            }
        }

        eta = eta * 0.95;

        if(iter % 1 == 0){
            {
                metrics tmp(0, 0);
                for(auto& client: clients){
                    tmp = tmp + client.evaluate_global();
                }

                rating MSE = sqrt(getMSE(tmp) / records_test.size());
                rating MAE = getMAE(tmp) / records_test.size();

                PRINT(os, MSE)
                PRINT(os, MAE)
                CSV(os_csv, iter, MSE, MAE)
            }
            
            {
                metrics tmp(0, 0);
                for(auto& client: clients){
                    tmp = tmp + client.evaluate_self();
                }

                rating MSE = sqrt(getMSE(tmp) / records.size());
                rating MAE = getMAE(tmp) / records.size();

                PRINT(os, MSE)
                PRINT(os, MAE)
                CSV(os_csv, iter, MSE, MAE)
            }
           
        }
    }
}

// void Server::performance() {
//     metrics m = evaluate();
//     os_tmp << getMSE(m) << " " << getMAE(m) << endl;
// }
