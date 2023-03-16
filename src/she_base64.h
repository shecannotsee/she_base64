//
// Created by shecannotsee on 2023/3/16.
//

#ifndef SHE_BASE64_SRC_SHE_BASE64_H_
#define SHE_BASE64_SRC_SHE_BASE64_H_

#include <string>

class she_base64 {
 private:
  static const char* base64;
  static const char* safe_url_base64;

  static unsigned char pos_of_char(unsigned char chr);

 public:
  enum class BASE_TYPE : unsigned char {
    BASE64,
    SAFE_URL_BASE64
  };

 public:
  /* Convert binary stream data >>>to>>> base64 encoding */
  static std::string encode(std::string data,BASE_TYPE base64_type = BASE_TYPE::BASE64);

  /* Convert base64 encoding >>>to>>>  binary stream data */
  static std::string decode(const std::string& data_base64);

};

#endif //SHE_BASE64_SRC_SHE_BASE64_H_
