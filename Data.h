//
// Created by mac on 2021/6/7.
//

#ifndef RS_DATA_H
#define RS_DATA_H

#include <string>
#include <vector>
#include <Eigen/Dense>
#include "Client.h"

using namespace std;
using namespace Eigen;




extern vector<Record> records;




void readTrainData(const string& filename);
void readTestData(const string& filename);


#endif //RS_DATA_H
