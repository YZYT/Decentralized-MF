#include <iostream>

using namespace std;
double ALPHA[] = {0.01};
// double ALPHA[] = {0.1, 0.01, 0.001};
double GAMMA[] = {0.01};
// double GAMMA[] = {0.1, 0.01, 0.001};
char buffer[1000];
void exec(int n, double alpha, double gamma){
    sprintf(buffer, "./build/RS -traindata ML100K/ML100K_copy%d_train.txt -testdata ML100K/ML100K_copy%d_valid.txt -output copy%d_valid -T 300 -alpha %f -eta %f", n, n, n, alpha, gamma);
    system(buffer);
}
int main(int argc, char *argv[]){
    for(auto alpha: ALPHA){
        for(auto gamma: GAMMA){
            exec(1, alpha, gamma);
            exec(2, alpha, gamma);
            exec(3, alpha, gamma);
            exec(4, alpha, gamma);
            exec(5, alpha, gamma);
        }
    }
    
}