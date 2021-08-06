#include "Server.h"

void Server::train() {
    
    float min_mse = -1;
    int early_stop_cnt = 0;
    
    int iter = 0;
    for(; iter <= 5; iter ++){
        // CERR(iter)
        for(auto record: records){
            uid u = record.u;
            iid i = record.i;
            rating r = record.r;
            VectorXd grad_u(MAXK), grad_p(4);
            MatrixXd grad_Q(4, 20);
            update(u, i, r, grad_u, grad_p, grad_Q);
        }
        eta = eta * 0.99;


        float dev_mse = getMSE(evaluate());
        float train_mse = getMSE(evaluate_local());
        loss_record_dev.push_back(dev_mse);
        loss_record_train.push_back(train_mse);

        if(min_mse < 0 || dev_mse < min_mse){
            min_mse = dev_mse;
            early_stop_cnt = 0;
            printf("Saving model... (epoch =%4d,  loss = %.4f)\n", iter, min_mse);
            // saveModel();
        }
        else{
            early_stop_cnt ++;
            if(early_stop_cnt > early_stop){
                break;
            }
        }
        if(iter % 1 == 0){
            CERR(iter)
            cout << "TEST:" << endl;
            {
                PRINT(os, dev_mse)
                // metrics tmp = evaluate();
                // rating MSE = getMSE(tmp);
                // rating MAE = getMAE(tmp);
                // PRINT(os, MSE)
                // PRINT(os, MAE)
                // CSV(os_csv, iter, MSE, MAE)
            }
            cout << "TRAIN:" << endl;
            {
                PRINT(os, train_mse)
                // metrics tmp = evaluate_local();
                // rating MSE = getMSE(tmp);
                // rating MAE = getMAE(tmp);
                // PRINT(os, MSE)
                // PRINT(os, MAE)
                // CSV(os_csv, iter, MSE, MAE)
            }
            cout << "OBJ:" << endl;
            cout << evaluate_loss() << endl;
        }
    }
    printf("Finished training after %d epochs.\n", iter);
    // save_learning_curve();
    // printU();
}

void Server::update(uid u, iid i, rating r, VectorXd& grad_u, VectorXd& grad_p, MatrixXd& grad_Q){
    VectorXd U_u = U.row(u);
    VectorXd P_i = P.row(i);
    rating e = 1.0 * r - predict(u, i);
    grad_u = -e * P_i * Q + alpha * U_u;
    grad_p = -e * U_u * Q.transpose() + alpha * P_i;
    grad_Q = -e * P_i.transpose() * U_u + alpha * Q;

    // cout << grad_u << endl << grad_p << endl << grad_Q << endl;

    U.row(u) -= eta * grad_u;
    P.row(i) -= eta * grad_p;
    Q -= eta * grad_Q;
}

metrics Server::evaluate() {
    rating MSE = 0, MAE = 0;
    for(auto record: records_test){
        uid u = record.u;
        iid i = record.i;
        rating r = record.r;
        rating r_hat = predict(u, i);
        MSE += (r - r_hat) * (r - r_hat);
        MAE += fabs(r - r_hat);
    }
    MSE = sqrt(MSE / records_test.size());
    MAE = MAE / records_test.size();
    return metrics(MSE, MAE);
}

float Server::evaluate_loss() {
    float Loss = 0;
    for(auto record: records){
        uid u = record.u;
        iid i = record.i;
        rating r = record.r;
        rating r_hat = predict(u, i);
        Loss += (r - r_hat) * (r - r_hat);
        // Loss += U.row(u).norm() * U.row(u).norm();
        // Loss += V.row(i).norm() * V.row(i).norm();
    }
    return Loss;
}

metrics Server::evaluate_local() {
    rating MSE = 0, MAE = 0;
    for(auto record: records){
        uid u = record.u;
        iid i = record.i;
        rating r = record.r;
        rating r_hat = predict(u, i);
        MSE += (r - r_hat) * (r - r_hat);
        MAE += fabs(r - r_hat);
    }
    MSE = sqrt(MSE / records.size());
    MAE = MAE / records.size();
    return metrics(MSE, MAE);
}

void Server::printU() {
    // f(i, 1, 1682){
    //     // CERR(U.row(i).norm());
    //     CSV(os_debug_csv, V.row(i).norm(), average_rating_item[i] / active_item[i], active_item[i]);
    // }

    f(i, 1, 943){
        // CERR(U.row(i).norm());
        CSV(os_debug_csv, U.row(i).norm(), average_rating[i] / active[i], active[i]);
    }
}


rating Server::predict(uid u, iid i){
    VectorXd U_u = U.row(u);
    VectorXd P_i = P.row(i);
    return (U_u.transpose() * P_i * Q)(0);
}

void Server::performance() {
    metrics m = evaluate();
    os_tmp << getMSE(m) << " " << getMAE(m) << endl;
}