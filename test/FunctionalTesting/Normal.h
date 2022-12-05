//
// Created by shecannotsee on 2022/12/2.
//

#ifndef SHE_BASE64_TEST_TEST_FUNCTIONALTESTING_NORMAL_H_
#define SHE_BASE64_TEST_TEST_FUNCTIONALTESTING_NORMAL_H_

#include <random>
#include <gtest/gtest.h>
//#include <sheBase64/sheBase64.h>
#include "sheBase64.h"
#include "../base64/base64.h"


namespace FunctionalTesting{

namespace Normal{
  TEST(sheBase64,single_char){
    std::random_device rd;
    for (int i=0;i<100;i++) {
      std::string a = std::to_string(rd());
      std::string ss;
      Base64::Encode(a,&ss);
      EXPECT_STREQ(sheBase64::encode(a).c_str(), ss.c_str())<<a;
      std::cout<<a<<":"<<ss<<std::endl;
      std::string sss;
      Base64::Decode(ss,&sss);
      EXPECT_STREQ(sheBase64::decode(ss).c_str(), sss.c_str())<<a;
    };

  };

  int testStart(){
    testing::InitGoogleTest();;
    return RUN_ALL_TESTS();// 运行所有测试单元
  };
}

};// namespace FunctionalTesting

#endif //SHE_BASE64_TEST_TEST_FUNCTIONALTESTING_NORMAL_H_
