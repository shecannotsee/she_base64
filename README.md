sheBase64 is a cpp-base64 library

Authors: shecannotsee (shecannotsee@163.com)

# Features

Library is header only, so you can just copy ./include/sheBase64/sheBase64.h where you want it.

Another way is to use cmake to build libraries just like the following building.

# Documentation

example

```c++
#include <iostream>
#include "include/she_base64/she_base64.h"// header only

int main() {
  std::string temp = "retrain";
  // data to base64
  std::cout<<she_base64::encode(temp)<<std::endl;
  // base to data
  std::cout<<she_base64::decode(she_base64::encode(temp))<<std::endl;

  return 0;
}
```



# Getting the Source

```bash
git clone --recurse-submodules https://github.com/shecannotsee/sheBase64.git
# Build Dependencies: to build gtest
./BuildDependencies.sh
```

# Building

This project supports [CMake](https://cmake.org/) out of the box.

### Build for Linux or Mac

```bash
# now you are in the directory ${path}/sheBase64
➜ pwd
${path}/sheBase64
➜ mkdir build
➜ cd build
➜ cmake ..
➜ make
➜ make install DESTDIR=${path}/sheBase64lib
```

