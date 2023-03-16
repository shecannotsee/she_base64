//
// Created by shecannotsee on 2023/3/16.
//

#ifndef SHE_BASE64_SRC_SHE_BASE64_H_
#define SHE_BASE64_SRC_SHE_BASE64_H_

#include <string>

class she_base64 {
  using byte = unsigned char;
 private:
  static const char base64[];
  static const char safe_url_base64[];
  static byte pos_of_char(const char& chr);
  static bool check_base64_success(const std::string& base64_data);

 public:
  enum class BASE_TYPE : byte {
    BASE64,
    SAFE_URL_BASE64
  };

 public:
  /* Convert binary stream data >>>to>>> base64 encoding */
  static std::string encode(std::string data,BASE_TYPE base64_type = BASE_TYPE::BASE64);

  /* Convert base64 encoding >>>to>>>  binary stream data */
  static std::string decode(const std::string& base64_data);

};

#endif //SHE_BASE64_SRC_SHE_BASE64_H_
