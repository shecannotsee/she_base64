//
// Created by shecannotsee on 2023/3/16.
//

#ifndef SHE_BASE64_TEST_M2_COMPARE_TEST_H_
#define SHE_BASE64_TEST_M2_COMPARE_TEST_H_

#include <string>

#include <she_base64.h>
#include <gtest/gtest.h>

namespace m2_compare_test {

TEST(base64_compare_test, encoding_common) {
  // 测试 Base64 编码函数
  EXPECT_EQ(she_base64::encode("Hello, world!"), "SGVsbG8sIHdvcmxkIQ==");
};

int main(int argc,char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
};

};// namespace m2_compare_test

#endif //SHE_BASE64_TEST_M2_COMPARE_TEST_H_
