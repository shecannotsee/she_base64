cd libraries
mkdir googletest
cd ..

cd 3rd
cd googletest
mkdir build
cd build
cmake ..
make -j7
make DESTDIR=../../../libraries/googletest install