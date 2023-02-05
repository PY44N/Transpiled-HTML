#pragma once

#include <string>
#include <vector>

#include "./token.h"

class Lexer {
private:
  std::string input;

  std::string readUntil(char chr, unsigned long long &currentChar);

public:
  Lexer(std::string &input);

  std::vector<Token> lex();
};