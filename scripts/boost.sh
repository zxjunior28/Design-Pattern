#!/bin/bash
rm -rf build/
cmake -S . -B build/ -DBUILD_EXAMPLES=ON
cmake --build build/ -j4
./build/bin/decorator_example
./build/bin/strategy_example
./build/bin/factory_example
# "data/case0.txt"