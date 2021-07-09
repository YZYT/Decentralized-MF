#include <iostream>
#include <fstream>
using namespace std;
#define DEBUG(os,x) os << #x << " : " << x << endl;
int main(int, char**) {
    ifstream os;
    os.open("../data/ML100K/ML100K_copy1_train.txt");
    int u, i, r, t;
    if(os >> u >> i >> r >> t){
        cout << "OK" << " " << u << endl;
    }
    else{
        cout << "FAILED" << endl;
    }

}
