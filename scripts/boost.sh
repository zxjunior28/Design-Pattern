#!/bin/bash
rm -rf build/
cmake -S . -B build/ -DBUILD_EXAMPLES=ON
cmake --build build/ -j4
# ./build/bin/decorator_example
# ./build/bin/strategy_example
# ./build/bin/factory_example
# ./build/bin/composite_example
./build/bin/bridge_example
./build/bin/chain_of_responsibility
# "data/case0.txt"