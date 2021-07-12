#include "Server.h"


void Server::initParam(){
    srand(time(0));
    

    for(auto& client: clients){
        client.initParam();
    }

}

void Server::train() {
    // random_shuffle(records.begin(), records.end());
    metrics tmp(0, 0);
    for(auto& client: clients){
        tmp = tmp + client.evaluate_global();
    }
    rating MSE = getMSE(tmp) / records_test.size();
    rating MAE = getMAE(tmp) / records_test.size();
    PRINT(os, MSE)
    PRINT(os, MAE)



    f(iter, 1, T * 5){
        CERR(iter)
        int num = 0;
        for(auto& client: clients){
            client.train();
        }
        // assert(1 == 0);

        for(auto& client: clients){
            client.reach_consensus();
        }
        
        if(T % 5 == 0) eta = eta * 0.9;
        if(iter % 10 == 0){
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