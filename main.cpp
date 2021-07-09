#include "base.h"
#include "Data.h"
#include "Server.h"

int main(int argc, char *argv[]) {
    clock_t startTime,endTime;
    startTime = clock();//计时开始
    readConfig(argc, argv);
    readTrainData(traindata);
    readTestData(testdata);
    initParam();
    Server::train();
    endTime = clock();
    cout << 1.0 * (endTime - startTime) / CLOCKS_PER_SEC << endl;
//    MatrixXd a(2, 2);
//    MatrixXd b(2, 2);
//    a(0, 0) = 1;
//    a(0, 1) = 2;
//    a(1, 0) = 3;
//    a(1, 1) = 4;

//    b(0, 0) = 5;
//    b(0, 1) = 6;
//    b(1, 0) = 7;
//    b(1, 1) = 8;

//    MatrixXd t1 = a.row(0);
//    MatrixXd t2 = b.row(0);
//    cout << (t1 * t2.transpose())(0) << endl;

    return 0;

//    background_task f;
//    thread my_thread(f);
//    my_thread.join();
//    cout << f.a << endl;
//    return 0;
//    char buff[] = "hello";
//    thread g(gg, ref(buff));
//    g.join();
//    cout << buff << endl;

//    clock_t st, ed;
//
//    MatrixXd a = MatrixXd::Random(5000,5000);
//    MatrixXd b = MatrixXd::Random(5000,5000);
//    st = clock();
//    MatrixXd c = a * b;
//    ed = clock();
//    cout << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;


//    CMatrix m1(5000, 5000, RANDOM);
//    CMatrix m2(5000, 5000, RANDOM);
//    st = clock();
//    CMatrix ans = m1 * m2;
//    ed = clock();
//    cout << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;


//    ConfigurationsReader::readConfigurations(var0);
//    DataReader::readData();
//    Initializer::initialization();
//    Server::train(Data.num_iterations);
//    Test.test();

    return 0;
}

