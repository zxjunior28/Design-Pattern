rm -rf build/
cmake -S . -B build/ -DBUILD_EXAMPLES=ON
cmake --build build/ -j4
./build/bin/decorator
# "data/case0.txt"