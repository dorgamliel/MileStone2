cmake_minimum_required(VERSION 3.15)
project(tempForServer)

set(CMAKE_CXX_STANDARD 14)

add_executable(tempForServer main.cpp MySerialServer.cpp MySerialServer.h Server.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h CacheManager.h FileCacheManager.cpp FileCacheManager.h Solver.h StringReverser.h StringReverser.cpp)

SET(CMAKE_CXX_FLAGS -pthread)