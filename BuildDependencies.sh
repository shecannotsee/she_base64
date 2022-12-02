#!/bin/bash
cd libraries
mkdir googletest
cd ..

# Compile googletest and install it to the specified directory
cd 3rd
cd googletest
mkdir build
cd build
cmake ..
make -j7
make DESTDIR=../../../libraries/googletest install

# move googletest's include and lib
cd ../../../libraries/googletest
mv -f ./usr/local/include ./
mv -f ./usr/local/lib ./
rm -rf ./usr