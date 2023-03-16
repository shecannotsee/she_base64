//
// Created by shecannotsee on 2023/3/16.
//

#include "she_base64.h"
#include <stdexcept>

const char* she_base64::base64 = {
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789"
    "-_"
};

const char* she_base64::safe_url_base64 = {
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789"
    "-_"
};

unsigned char she_base64::pos_of_char(const unsigned char chr) {
  if      (chr >= 'A' && chr <= 'Z') return chr - 'A';
  else if (chr >= 'a' && chr <= 'z') return chr - 'a' + ('Z' - 'A')               + 1;
  else if (chr >= '0' && chr <= '9') return chr - '0' + ('Z' - 'A') + ('z' - 'a') + 2;
  else if (chr == '+' || chr == '-') return 62;
  else if (chr == '/' || chr == '_') return 63;
  else
    throw std::runtime_error("Input is not valid base64-encoded data.");
};

std::string she_base64::encode(std::string data,BASE_TYPE base64_type) {
  int base64_tail_fill = data.size() % 3;
  unsigned char zero = 0x00;
  if ( base64_tail_fill == 1 ) {
    data += zero;
    data += zero;
  } else if ( base64_tail_fill == 2 ) {
    data += zero;
  }

  // confirm base64 or safe url base64
  const char* base64_table_table;
  if (base64_type == BASE_TYPE::BASE64) {
    base64_table_table = she_base64::base64;
  } else if (base64_type == BASE_TYPE::SAFE_URL_BASE64) {
    base64_table_table = she_base64::safe_url_base64;
  }

  std::string base64_str;
  for (int i=0; i < data.size(); i=i+3 ) {
    unsigned char a;
    a = static_cast<unsigned char>(data[i])>>2;
    unsigned char b;
    b = static_cast<unsigned char>(data[i])<<6;
    b = b>>2;
    b += static_cast<unsigned char>(data[i+1])>>4;
    unsigned char c;
    c = static_cast<unsigned char>(data[i+1])<<4;
    c = c>>2;
    c += static_cast<unsigned char>(data[i+2])>>6;
    unsigned char d;
    d = static_cast<unsigned char>(data[i+2])<<2;
    d = d>>2;
    base64_str += base64_table_table[a];
    base64_str += base64_table_table[b];
    base64_str += base64_table_table[c];
    base64_str += base64_table_table[d];
  }

  // Add end : =
  if ( base64_tail_fill == 1 ) {
    base64_str[base64_str.size()-1] = '=';
    base64_str[base64_str.size()-2] = '=';
  } else if ( base64_tail_fill == 2 ) {
    base64_str[base64_str.size()-1] = '=';
  }

  return base64_str;
};

std::string she_base64::decode(const std::string& data_base64) {
  int tail_fill = 0;

  for (int i = data_base64.size()-1; i>=0 ; --i ) {
    if (data_base64[i] == '=') tail_fill++;
    else break;
  }

  int data_real_length = (data_base64.size()/4 )* 3 - tail_fill ;

  std::string data;
  unsigned char temp = 0x00;
  int index = 0;
  for (auto ch : data_base64) {
    if (data.size() == data_real_length) {
      break;
    } else if (index == 0) {
      temp += she_base64::pos_of_char(ch)<<2;
      index = 6;
    } else if (index == 6) {
      temp += she_base64::pos_of_char(ch)>>4;
      data += temp;
      temp = 0x00;
      temp = she_base64::pos_of_char(ch)<<4;
      index = 4;
    } else if ( index == 4 ) {
      temp += she_base64::pos_of_char(ch)>>2;
      data += temp;
      temp = 0x00;
      temp = she_base64::pos_of_char(ch)<<6;
      index = 2;
    } else if ( index == 2 ) {
      temp += she_base64::pos_of_char(ch);
      data += temp;
      temp = 0x00;
      index = 0;
    }
  };

  return data;
};
