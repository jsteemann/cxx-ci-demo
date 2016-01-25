ulimit -c unlimited -S # enable core files
mkdir -p build # create build directory if it does not exists
(cd build; cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=$CXX .. && make) # make
(cd tests && ctest -V) # run tests

