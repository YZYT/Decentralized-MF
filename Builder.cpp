#include "Builder.h"

Server* Builder::build(int argc, char *argv[]){
    server = new Server;
    readConfig(argc, argv);

    // CERR(server->clients.size());
     
    readTrainData(traindata);
    readTestData(testdata);

    // CERR(server->clients.size());
  

    buildGraph();

    // CERR(server->clients.size());
    return server;
}

void Builder::readConfig(int argc, char *argv[]){
    f(i, 1, argc - 1){
        if(!strcmp(argv[i], "-alpha")) alpha = atof(argv[++ i]);
        else if(!strcmp(argv[i], "-eta")) eta = atof(argv[++ i]);
        else if(!strcmp(argv[i], "-traindata")) traindata = "data/" + string(argv[++ i]);
        else if(!strcmp(argv[i], "-testdata")) testdata = "data/" + string(argv[++ i]);
        else if(!strcmp(argv[i], "-output")){
            output = "results/" + string(argv[++ i]);
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
    vector<Client>& clients = server->clients;



    while(fin >> u >> i >> r >> t){
        assert(u < MAXN);
        clients[u].rate(i, r);
        records.push_back({u, i, r});
    }


    for(auto& client: clients){
        sort(client.I_u.begin(), client.I_u.end());
    }

    fin.close();
}

void Builder::readTestData(const string& filename){
    ifstream fin(filename);
    uid u;
    iid i;
    rating r;
    string t;
    cout << filename << endl;
    vector<Client>& clients = server->clients;

    while(fin >> u >> i >> r >> t){
        clients[u].rate_test(i, r);
        records_test.push_back({u, i, r});
    }
    fin.close();
}

void Builder::buildGraph(){
    vector<Client>& clients = server->clients;
    double SAVED = 0;

    int NUM = 0;

    f(i, 0, MAXN - 1){
        f(j, i + 1, MAXN - 1){
            double w;
            w = calcSimilarity(clients[i], clients[j]);
            if(w == 0){
                SAVED += 1;
                continue;
            }

            server->clients[i].neighbours.push_back({&(server->clients[j]), w, i, j});
            server->clients[j].neighbours.push_back({&(server->clients[i]), w, j, i});
        }
        // cout << i << " " << clients[i].I_u.size() << " " << clients[i].neighbours.size() << endl;
    }

    SAVED /= MAXN * MAXN / 2;
    CERR(SAVED)
}

double Builder::calcSimilarity(Client& u, Client& v){
    if(u.I_u.empty() || v.I_u.empty()) return 0;

    vector<Interaction> res;
    auto u_it = u.I_u.begin();
    auto v_it = v.I_u.begin();
    int cnt = 0;
    while(u_it != u.I_u.end() && v_it != v.I_u.end()){
        if(*u_it < *v_it) u_it ++;
        else if(*u_it > *v_it) v_it ++;
        else{
            cnt ++;
            u_it ++;
            v_it ++;
        }
    }
    if(cnt < 25) return 0;
    return cnt / sqrt(1.0 *  u.I_u.size() * v.I_u.size());
}
