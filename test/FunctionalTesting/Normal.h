//
// Created by shecannotsee on 2022/12/2.
//

#ifndef SHE_BASE64_TEST_TEST_FUNCTIONALTESTING_NORMAL_H_
#define SHE_BASE64_TEST_TEST_FUNCTIONALTESTING_NORMAL_H_

#include <gtest/gtest.h>
#include <sheBase64/sheBase64.h>

namespace FunctionalTesting{

namespace Normal{
  TEST(sheBase64,single_char){
    for (int i=0;i<64;i++) {
      std::string s = "\0";
      EXPECT_STREQ(s.c_str(), sheBase64::base64_table[0][i]);
    };
  };

  int testStart(){
    testing::InitGoogleTest();;
    return RUN_ALL_TESTS();// 运行所有测试单元
  };
}

};// namespace FunctionalTesting

#endif //SHE_BASE64_TEST_TEST_FUNCTIONALTESTING_NORMAL_H_
