//
// Created by shecannotsee on 2022/12/5.
//

#ifndef SHE_BASE64_SRC_SHEBASE64_H_
#define SHE_BASE64_SRC_SHEBASE64_H_

#include <string>
#include <iostream>

namespace sheBase64 {
/*
 * [0][x]:base64,base64编码结果中会有+、/、=三个特殊字符，它们在url中属于特殊字符是直接无法传递的；
 * [1][x]:SafeUrlBase64,base64url其实就是把字符中的'+'和'/'分别替换成'-'和'_'，另外把末尾填充的‘=’去掉;其他都一样。
 */
static const char* base64_table[2] ={
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789"
    "+/",
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789"
    "-_"
};

static unsigned char pos_of_char(const unsigned char chr);

/* Convert binary stream data to base64 encoding */
std::string encode(std::string data);

/* Convert base64 encoding to  binary stream data */
std::string decode(std::string data_base64);

};//namespace sheBase64

#endif //SHE_BASE64_SRC_SHEBASE64_H_
