#include "./lexer.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "./stringutils.h"

Lexer::Lexer(std::string &input) { this->input = input; }

std::string Lexer::readUntil(char chr, unsigned long long &currentChar) {
  currentChar++;

  std::string ret = "";

  while (input.at(currentChar) != chr) {
    ret.push_back(input.at(currentChar));
    currentChar++;
  }

  return ret;
}

std::map<char, TokenType> tokenMap = {
    {'(', TokenType::OPEN_PAREN},   {')', TokenType::CLOSE_PAREN},
    {'{', TokenType::OPEN_BRACKET}, {'}', TokenType::CLOSE_BRACKET},
    {'[', TokenType::OPEN_BRACKET}, {']', TokenType::CLOSE_BRACKET},
    {',', TokenType::COMMA},        {'=', TokenType::EQUALS}};

std::vector<Token> Lexer::lex() {
  std::vector<Token> vec = {};

  std::string propertyBuilder = "";
  for (unsigned long long i = 0; i < input.length(); i++) {
    char chr = input.at(i);
    if (tokenMap.find(chr) != tokenMap.end()) {
      vec.push_back(
          Token(TokenType::PROPERTY, StringUtils::trim(propertyBuilder)));
      propertyBuilder = "";
      vec.push_back(Token(tokenMap.at(chr), std::string(1, chr)));
    } else if (chr == '"') {
      vec.push_back(
          Token(TokenType::PROPERTY, StringUtils::trim(propertyBuilder)));
      propertyBuilder = "";
      vec.push_back(Token(TokenType::STRING, readUntil('"', i)));
    } else {
      propertyBuilder.push_back(chr);
    }
  }

  // TODO: Remove empty properties

  return vec;
}
