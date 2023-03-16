//
// Created by shecannotsee on 2023/3/16.
//

#ifndef SHE_BASE64_SRC_SHE_BASE64_H_
#define SHE_BASE64_SRC_SHE_BASE64_H_

#include <string>

class she_base64 {
  using byte = unsigned char;
 private:
  static const char base64[] = {
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"  // 00-25
      "abcdefghijklmnopqrstuvwxyz"  // 26-51
      "0123456789"                  // 52-61
      "+/"                          // 62-63
  };

  static const char safe_url_base64[] =  = {
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"  // 00-25
    "abcdefghijklmnopqrstuvwxyz"  // 26-51
    "0123456789"                  // 52-61
    "-_"                          // 62-63
  };

  static byte pos_of_char(const char& chr) {
    if      (chr >= 'A' && chr <= 'Z') return chr - 'A';
    else if (chr >= 'a' && chr <= 'z') return chr - 'a' + ('Z' - 'A')               + 1;
    else if (chr >= '0' && chr <= '9') return chr - '0' + ('Z' - 'A') + ('z' - 'a') + 2;
    else if (chr == '+' || chr == '-') return 62;
    else if (chr == '/' || chr == '_') return 63;
    else
      throw std::runtime_error("Input is not valid base64-encoded data.");
  };

  static bool check_base64_success(const std::string& base64_data) {
    if (base64_data.length() % 4 != 0) {
      return false;
    }
    for (char base64_char : base64_data) {
      try {
        if (base64_char!='=') {
          pos_of_char(base64_char);
        }
      }
      catch (const std::runtime_error& exc) {
        std::cout << exc.what() <<std::endl;
        return false;
      }
    }
    return true;
  };;

 public:
  enum class BASE_TYPE : byte {
    BASE64,
    SAFE_URL_BASE64
  };

 public:
  /* Convert binary stream data >>>to>>> base64 encoding */
  static std::string encode(std::string data,BASE_TYPE base64_type = BASE_TYPE::BASE64)  {
    int base64_tail_fill = data.size() % 3;
    byte zero = 0x00;
    if ( base64_tail_fill == 1 ) {
      data += zero;
      data += zero;
    } else if ( base64_tail_fill == 2 ) {
      data += zero;
    }

    // confirm base64 or safe url base64
    const char* base64_table_table = nullptr;
    if (base64_type == BASE_TYPE::BASE64) {
      base64_table_table = she_base64::base64;
    } else if (base64_type == BASE_TYPE::SAFE_URL_BASE64) {
      base64_table_table = she_base64::safe_url_base64;
    }

    std::string base64_str(data.size()/3*4,'A');
    int index = 0;
    byte temp = 0x00;
    for (int i = 0; i < data.size(); i += 3) {
      // Data type needs to be converted first
      temp = (static_cast<byte>(data[i]))>>2;
      base64_str[index++] = base64_table_table[temp];

      temp = (static_cast<byte>(data[i]))<<6;
      temp = temp>>2;
      temp += (static_cast<byte>(data[i+1]))>>4;
      base64_str[index++] = base64_table_table[temp];

      temp = (static_cast<byte>(data[i+1]))<<4;
      temp = temp>>2;
      temp += (static_cast<byte>(data[i+2]))>>6;
      base64_str[index++] = base64_table_table[temp];

      temp = (static_cast<byte>(data[i+2]))<<2;
      temp = temp>>2;
      base64_str[index++] = base64_table_table[temp];
    };

    // Add end : =
    if ( base64_tail_fill == 1 ) {
      base64_str[base64_str.size()-1] = '=';
      base64_str[base64_str.size()-2] = '=';
    } else if ( base64_tail_fill == 2 ) {
      base64_str[base64_str.size()-1] = '=';
    }

    return base64_str;
  };;

  /* Convert base64 encoding >>>to>>>  binary stream data */
  static std::string decode(const std::string& base64_data) {
    if (!check_base64_success(base64_data)) {
      return std::string("");
    };
    int tail_fill = 0;

    for (int i = base64_data.size()-1; i>=0 ; --i ) {
      if (base64_data[i] == '=') tail_fill++;
      else break;
    }

    int data_real_length = (base64_data.size()/4 )* 3 - tail_fill ;

    std::string data;
    byte temp = 0x00;
    int index = 0;
    for (int i = 0; i < base64_data.size() ; i++) {
      if (data.size() == data_real_length) {
        break;
      } else if (index == 0) {
        temp += static_cast<byte>(she_base64::pos_of_char(base64_data[i]) << 2);
        index = 6;
      } else if (index == 6) {
        temp += static_cast<byte>(she_base64::pos_of_char(base64_data[i]) >> 4);
        data += temp;
        temp = 0x00;
        temp = static_cast<byte>(she_base64::pos_of_char(base64_data[i]) << 4);
        index = 4;
      } else if ( index == 4 ) {
        temp += static_cast<byte>(she_base64::pos_of_char(base64_data[i]) >> 2);
        data += temp;
        temp = 0x00;
        temp = static_cast<byte>(she_base64::pos_of_char(base64_data[i]) << 6);
        index = 2;
      } else if ( index == 2 ) {
        temp += static_cast<byte>(she_base64::pos_of_char(base64_data[i]));
        data += temp;
        temp = 0x00;
        index = 0;
      }
    };

    return data;
  };

};

#endif //SHE_BASE64_SRC_SHE_BASE64_H_
