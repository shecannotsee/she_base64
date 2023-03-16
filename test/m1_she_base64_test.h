//
// Created by shecannotsee on 2023/3/16.
//

#ifndef SHE_BASE64_TEST_M1_SHE_BASE64_TEST_H_
#define SHE_BASE64_TEST_M1_SHE_BASE64_TEST_H_

#include <string>

#include <she_base64.h>
#include <gtest/gtest.h>

namespace m1_she_base64_test {

TEST(Base64Test, encoding_common) {
  // 测试 Base64 编码函数
  EXPECT_EQ(she_base64::encode("Hello, world!"), "SGVsbG8sIHdvcmxkIQ==");
  EXPECT_EQ(she_base64::encode("12345"), "MTIzNDU=");
  EXPECT_EQ(she_base64::encode(""), "");
  EXPECT_EQ(she_base64::encode("The quick brown fox jumps over the lazy dog."), "VGhlIHF1aWNrIGJyb3duIGZveCBqdW1wcyBvdmVyIHRoZSBsYXp5IGRvZy4=");
};
TEST(Base64Test, encoding_special) {
  std::string input1;/* 0x00 0x01 0x02 */ {
    unsigned char temp1 = 0x00;
    input1 += temp1;
    input1 += (temp1 + 1);
    input1 += (temp1 + 2);
  };
  EXPECT_EQ(she_base64::encode(input1), "AAEC");
  std::string input2;/* 0xff 0xfe 0xfd : 63 63 59 61 //79*/ {
    unsigned char temp2 = 0xff;
    input2 += static_cast<char>(temp2);
    input2 += static_cast<char>(temp2 - 1);
    input2 += static_cast<char>(temp2 - 2);
  }
  EXPECT_EQ(she_base64::encode(input2), "//79");
};


TEST(Base64Test, decoding_common) {
  // 测试 Base64 解码函数
  EXPECT_EQ(she_base64::decode("SGVsbG8sIHdvcmxkIQ=="), "Hello, world!");
  EXPECT_EQ(she_base64::decode("MTIzNDU="), "12345");
  EXPECT_EQ(she_base64::decode(""), "");
  EXPECT_EQ(she_base64::decode("VGhlIHF1aWNrIGJyb3duIGZveCBqdW1wcyBvdmVyIHRoZSBsYXp5IGRvZy4="), "The quick brown fox jumps over the lazy dog.");
};
TEST(Base64Test, decoding_special) {
  std::string input1;/* 0x00 0x01 0x02*/ {
    unsigned char temp1 = 0x00;
    input1 += temp1;
    input1 += (temp1+1);
    input1 += (temp1+2);
  };
  EXPECT_EQ(she_base64::decode("AAEC"), std::string(input1));
  EXPECT_EQ(she_base64::decode("//79"), std::string("\xFF\xFE\xFD"));
};
TEST(Base64Test, decoding_error) {
  EXPECT_EQ(she_base64::decode("SGVsbG8sIHdvcmxkIQ"), ""); // 不完整的编码字符串
};

int main(int argc,char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
};

};// m1_she_base64_test

#endif //SHE_BASE64_TEST_M1_SHE_BASE64_TEST_H_
