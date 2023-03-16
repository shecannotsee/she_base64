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
  EXPECT_EQ(she_base64::encode("\x00\x01\x02"), "AAEC")
            <<"["<<she_base64::encode("\x00\x01\x02")<<"]\n";
  EXPECT_EQ(she_base64::encode("\xFF\xFE\xFD"), "/v7+")
            <<"["<<she_base64::encode("\xFF\xFE\xFD")<<"]\n";;
};


TEST(Base64Test, decoding_common) {
  // 测试 Base64 解码函数
  EXPECT_EQ(she_base64::decode("SGVsbG8sIHdvcmxkIQ=="), "Hello, world!");
  EXPECT_EQ(she_base64::decode("MTIzNDU="), "12345");
  EXPECT_EQ(she_base64::decode(""), "");
  EXPECT_EQ(she_base64::decode("VGhlIHF1aWNrIGJyb3duIGZveCBqdW1wcyBvdmVyIHRoZSBsYXp5IGRvZy4="), "The quick brown fox jumps over the lazy dog.");
};
TEST(Base64Test, decoding_special) {
  EXPECT_EQ(she_base64::decode("AAEC"), "\x00\x01\x02");
  EXPECT_EQ(she_base64::decode("/v7+"), "\xFF\xFE\xFD");
  EXPECT_EQ(she_base64::decode("SGVsbG8sIHdvcmxkIQ"), ""); // 不完整的编码字符串
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
