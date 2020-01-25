#include "Server.h"
#include "State.h"
#include "MatrixSearchable.h"
#include "MyClientHandler.h"
#include "MyParallelServer.h"
#include "AStar.h"
#include "BFS.h"
int main(int argc, char* argv[]) {
    int port;
    if (argv[1] != NULL) {
        port = atoi(argv[1]);
    } else {
        port = 5600;
    }
    /*test1::Main obj;
    obj.main(argc, argv);*/
    DFS<pair<int, int>> dfs;
    AStar<pair<int, int>> astar;
    BFS<pair<int, int>> bfs;
    BestFS<pair<int, int>> best;
    auto* solver = new SearcherAdapter<pair<int, int>>(&bfs);
    auto* c = new MyClientHandler(solver);
    MyParallelServer server;
    server.start(port, c);
    return 0;
}
