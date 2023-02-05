#include <iostream>
#include <vector>

#include "./fs.h"
#include "./lexer.h"

int main() {
  std::string content = FS::readFile("in.thtml");

  Lexer lexer(content);

  std::vector<Token> tokens = lexer.lex();

  for (int i = 0; i < tokens.size(); i++) {
    Token v = tokens.at(i);
    std::cout << v.type << " : " << v.value << std::endl;
  }

  return 0;
}