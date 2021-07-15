#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "omp.h"
#include <sys/time.h> 

using namespace std;
#define DEBUG(os,x) os << #x << " : " << x << endl;
const int MAXN = 1e5;
class Client{
public:
    int a[MAXN];
    int sum;
    int Run(){
        sum = 0;
        for(int i = 1; i<= 50; i++) {
            for (int i = 1; i <= MAXN - 1; i++) {
                a[i] += rand();
            }
        }
        cout << "Q " << endl;
        return a[MAXN - 1];
    }
};
Client client[50];

int main(int, char**) {

    omp_set_num_threads(50);
    struct timeval time1,time2; 
    gettimeofday(&time1,NULL);

    #pragma omp parallel for
    for (int i = 0; i < 6; i++)
		client[i].Run();
	cout << "GG" << endl;

    gettimeofday(&time2,NULL); 
    time2.tv_sec-=time1.tv_sec; 
    time2.tv_usec-=time1.tv_usec; 
    if (time2.tv_usec<0L) { 
        time2.tv_usec+=1000000L; 
        time2.tv_sec-=1; 
    } 
    printf("Executiontime=%ld.%06ld seconds\n",time2.tv_sec,time2.tv_usec); 
    

   
    gettimeofday(&time1,NULL);
    for (int i = 0; i < 6; i++)
		client[i].Run();

    gettimeofday(&time2,NULL); 
    time2.tv_sec-=time1.tv_sec; 
    time2.tv_usec-=time1.tv_usec; 
    if (time2.tv_usec<0L) { 
        time2.tv_usec+=1000000L; 
        time2.tv_sec-=1; 
    } 
    printf("Executiontime=%ld.%06ld seconds\n",time2.tv_sec,time2.tv_usec); 

}
