cmake_minimum_required(VERSION 3.20)
project(cpp-system)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 実行ファイルの出力ディレクトリを統一
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_executable(cpp-system src/main.cpp)