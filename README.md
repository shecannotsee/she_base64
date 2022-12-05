A c++style base64 interface

BuildDependencies.sh : use to build gtest



# Features



# Documentation





# Getting the Source

```bash
git clone --recurse-submodules https://github.com/shecannotsee/sheBase64.git
# Build Dependencies
./BuildDependencies.sh
```



# Building

This project supports [CMake](https://cmake.org/) out of the box.

### Build for Linux or Mac

```bash
# now you are in the directory ${path}/sheBase64
mkdir build
cmake ..
make
make install DESTDIR=${install_path}
```

