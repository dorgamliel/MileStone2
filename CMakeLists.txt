cmake_minimum_required(VERSION 3.15)
project(MileStone2)

set(CMAKE_CXX_STANDARD 14)

<<<<<<< HEAD
add_executable(MileStone2 main.cpp MySerialServer.cpp MySerialServer.h Server.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h CacheManager.h FileCacheManager.cpp FileCacheManager.h Solver.h StringReverser.h StringReverser.cpp Searchable.h Searcher.h BestFS.cpp BestFS.h DFS.cpp DFS.h State.cpp State.h MatrixSearchable.h MatrixSearchable.cpp SearcherAdapter.h BFS.h BFS.cpp AStar.cpp AStar.h)
=======
add_executable(MileStone2 main.cpp MySerialServer.cpp MySerialServer.h Server.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h CacheManager.h FileCacheManager.cpp FileCacheManager.h Solver.h StringReverser.h StringReverser.cpp Searchable.h Searcher.h BestFS.cpp BestFS.h DFS.cpp DFS.h State.cpp State.h MatrixSearchable.h MatrixSearchable.cpp SearcherAdapter.h BFS.h BFS.cpp MyParallelServer.cpp MyParallelServer.h)
>>>>>>> 9c360b3a728775ac2d2e3b55a8bb21a7de8f1f3c

SET(CMAKE_CXX_FLAGS -pthread)