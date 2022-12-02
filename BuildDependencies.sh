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

cd ../../../libraries/googletest
mv -f ./usr/local/include ./
mv -f ./usr/local/lib ./
rm -rf ./usr