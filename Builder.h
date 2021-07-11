
#ifndef RS_BUILDER_H
#define RS_BUILDER_H

#include "Base.h"

using namespace std;


class Builder {
public:
    Builder()=default;
    Builder(int argc, char *argv[]);
private:
    void readConfig(int argc, char *argv[]);
    void readTrainData(const string& filename);
    void readTestData(const string& filename);
    void initParam();
};


#endif //RS_BUILDER_H