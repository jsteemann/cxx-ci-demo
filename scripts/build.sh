echo "adjusting ulimits"
ulimit -c unlimited -S # enable core files
ulimit -a # print limits

mkdir -p build # create build directory if it does not exists

echo "building..."
(cd build; cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=$CXX .. && make) # make

echo "running tests..."
(cd build/tests && ctest -V) # run tests

