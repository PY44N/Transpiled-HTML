#include "./stringutils.h"

#include <algorithm>
#include <string>

const std::string WHITESPACE = " \n\r\t\f\v";

std::string StringUtils::ltrim(const std::string &s) {
  size_t start = s.find_first_not_of(WHITESPACE);
  return (start == std::string::npos) ? "" : s.substr(start);
}

std::string StringUtils::rtrim(const std::string &s) {
  size_t end = s.find_last_not_of(WHITESPACE);
  return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string StringUtils::trim(const std::string &s) { return rtrim(ltrim(s)); }