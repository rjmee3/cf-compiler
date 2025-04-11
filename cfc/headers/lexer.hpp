// lexer.hpp
#pragma once
#include <string>
#include <vector>

using namespace std;

enum class TokenType {
   // Single-char tokens
   PLUS, MINUS, STAR, SLASH, LPAREN, RPAREN,

   // Literals
   NUMBER,

   // End of Input
   EOF_TOKEN,
};

struct Token {
   TokenType type;
   string lexeme;
   int line;

   Token(TokenType type, string lexeme, int line)
      : type(type), lexeme(move(lexeme)), line(line) {}
};

vector<Token> lex(const string& source);
