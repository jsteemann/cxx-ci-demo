if [ "$COVERAGE" = "ON" ]; then 
  gem install coveralls-lcov
  # install lcov 1.11
  wget http://ftp.de.debian.org/debian/pool/main/l/lcov/lcov_1.11.orig.tar.gz
  tar xf lcov_1.11.orig.tar.gz
  make -C lcov-1.11/ install PREFIX=~/bin/lcov
fi

mkdir -p build # create build directory if it does not exist

echo "building..."
(cd build; cmake -DCMAKE_BUILD_TYPE=Debug -DCoverage=$COVERAGE -DCMAKE_CXX_COMPILER=$CXX .. && make)

echo "running tests..."
(cd build/tests && ctest -V)

if [ "$COVERAGE" = "ON" ]; then
  # collect coverage info
  ~/bin/lcov/usr/bin/lcov --directory build --capture --output-file build/coverage.info --gcov-tool=gcov-4.9
  ~/bin/lcov/usr/bin/lcov --remove build/coverage.info 'tests/*' '/usr/*' --output-file build/coverage.info --gcov-tool=gcov-4.9
  ~/bin/lcov/usr/bin/lcov --list build/coverage.info --gcov-tool=gcov-4.9
  # upload coverage info
  coveralls-lcov --repo-token ${COVERALLS_TOKEN} build/coverage.info
fi
