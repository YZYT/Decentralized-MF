#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define DEBUG(os,x) os << #x << " : " << x << endl;
class GG{
public:
    void work(int i){
        t[i].go();
    }
    void go(){
        cout << "QQ";
    }
};


int main(int, char**) {
    t[1].go();
    // ifstream os;
    // os.open("../data/ML100K/ML100K_copy1_train.txt");
    // int u, i, r, t;
    // if(os >> u >> i >> r >> t){
    //     cout << "OK" << " " << u << endl;
    // }
    // else{
    //     cout << "FAILED" << endl;
    // }
    pair<int, pair<int, int>> a(1, make_pair(2, 3));
    pair<int,int> b(1, 2);
    vector<pair<int,int>> vec;
    vec.push_back(b);

}