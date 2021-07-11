#include "Builder.h"
#include "Client.h"

Builder::Builder(int argc, char *argv[]){
    readConfig(argc, argv);
    readTrainData(traindata);
}

void Builder::readConfig(int argc, char *argv[]){
    f(i, 1, argc - 1){
        if(!strcmp(argv[i], "-alpha")) alpha = atof(argv[++ i]);
        else if(!strcmp(argv[i], "-eta")) eta = atof(argv[++ i]);
        else if(!strcmp(argv[i], "-traindata")) traindata = "../data/" + string(argv[++ i]);
        else if(!strcmp(argv[i], "-testdata")) testdata = "../data/" + string(argv[++ i]);
        else if(!strcmp(argv[i], "-output")){
            output = "../results/" + string(argv[++ i]);
            os.open(output + ".out");
            os_tmp.open(output + ".tmp");
            os_csv.open(output + ".csv");
        }
        else if(!strcmp(argv[i], "-T")) T = atoi(argv[++ i]);
    }
    PRINT(os, alpha)
    PRINT(os, eta)
    PRINT(os, traindata)
    PRINT(os, testdata)
    PRINT(os, output)
    PRINT(os, T)

    CSV(os_csv, "iter", "MSE", "MAE")

}

void Builder::readTrainData(const string& filename){
    ifstream fin(filename);
    uid u;
    iid i;
    rating r;
    string t;
    cout << filename << endl;
    while(fin >> u >> i >> r >> t){
        clients[u].rate(i, r);
        // records.push_back({u, i, r});
    }
    fin.close();
}