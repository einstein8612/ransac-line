#!/bin/sh

if [ "$1" = "--clean" ]; then
    echo "Cleaning build directory..."
    rm -rf build
fi

mkdir -p build
cd build
cmake ..
make
if [ $? -ne 0 ]; then
    echo "Build failed"
    exit 1
fi
ctest
