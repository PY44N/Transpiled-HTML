#pragma once

#include <string>

enum TokenType {
  OPEN_PAREN,
  CLOSE_PAREN,
  OPEN_BRACKET,
  CLOSE_BRACKET,
  EQUALS,
  COMMA,
  STRING,
  PROPERTY
};

class Token {
public:
  TokenType type;
  std::string value;

  Token(TokenType type, std::string value);
};