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
  unsigned char temp1 = 0x00;
  std::string input1;
  input1 += temp1;input1 += (temp1+1);input1 += (temp1+2);
  EXPECT_EQ(she_base64::encode(input1), "AAEC")
            <<"output is:["<<she_base64::encode("\x00\x01\x02")<<"]\n";


  unsigned char temp2 = 0xff;
  std::string input2;
  input2 += static_cast<char>(temp2);
  input2 += static_cast<char>(temp2-1);
  input2 += static_cast<char>(temp2-2);
  // 63 63 59 61 __79
  EXPECT_EQ(she_base64::encode(input2), "//79")
            <<"output is:["<<she_base64::encode("\xFF\xFE\xFD")<<"],should:[//79]\n";
};


TEST(Base64Test, decoding_common) {
  // 测试 Base64 解码函数
  EXPECT_EQ(she_base64::decode("SGVsbG8sIHdvcmxkIQ=="), "Hello, world!");
  EXPECT_EQ(she_base64::decode("MTIzNDU="), "12345");
  EXPECT_EQ(she_base64::decode(""), "");
  EXPECT_EQ(she_base64::decode("VGhlIHF1aWNrIGJyb3duIGZveCBqdW1wcyBvdmVyIHRoZSBsYXp5IGRvZy4="), "The quick brown fox jumps over the lazy dog.");
};
TEST(Base64Test, decoding_special) {
  unsigned char p1[3] = {0x00,0x01,0x02};
  EXPECT_EQ(she_base64::decode("AAEC"), std::string("\x00\x01\x02"))
            <<"output is:["<<she_base64::decode("AAEC")<<"],shoule:[]\n";

  unsigned char p2[3] = {0xff,0xfe,0xfd};
  EXPECT_EQ(she_base64::decode("//79"), std::string("\xFF\xFE\xFD"))
            <<"output is:["<<she_base64::decode("//79")<<"]shoule:[]\n";
};
TEST(Base64Test, decoding_error) {
  EXPECT_EQ(she_base64::decode("SGVsbG8sIHdvcmxkIQ"), "")
            <<"output is:["<<she_base64::decode("SGVsbG8sIHdvcmxkIQ")<<"]should:[]\n"; // 不完整的编码字符串
};

int main(int argc,char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
};

};// m1_she_base64_test

#endif //SHE_BASE64_TEST_M1_SHE_BASE64_TEST_H_
