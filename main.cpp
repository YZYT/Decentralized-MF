#include "Base.h"
#include "Data.h"
#include "Server.h"
#include "Builder.h"

int main(int argc, char *argv[]) {
    struct timeval time1,time2; 
    gettimeofday(&time1,NULL);

    Server* server = Builder().build(argc, argv);
    // CERR(server->clients.size());
    server->initParam();
    server->train();
    delete server;

    gettimeofday(&time2,NULL); 
    time2.tv_sec-=time1.tv_sec; 
    time2.tv_usec-=time1.tv_usec; 
    if (time2.tv_usec<0L) { 
        time2.tv_usec+=1000000L; 
        time2.tv_sec-=1; 
    } 
    printf("Executiontime=%ld.%06ld seconds\n",time2.tv_sec,time2.tv_usec); 



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

