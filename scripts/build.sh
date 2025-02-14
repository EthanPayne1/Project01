#!/bin/bash
BUILD_TYPE="Debug"
TARGET="All"
BUILD_ARGS=""
TEST_FLAGS=OFF

cmake -S . -B build -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DENABLE_TEST=$TEST_FLAGS $BUILD_ARGS
cmake --build build --target $TARGET

echo "\e[32mBuild finished in $SECONDS seconds.\e[0m"
