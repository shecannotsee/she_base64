#include <string>
#include <iostream>
#include <she_base64.h>

int main() {
  std::string temp = "retrain";
  // data to base64
  std::cout<<she_base64::encode(temp)<<std::endl;
  // base to data
  std::cout<<she_base64::decode(she_base64::encode(temp))<<std::endl;

  return 0;
};
