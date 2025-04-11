// lexer.hpp
#pragma once
#include <string>
#include <vector>
#include <stdexcept>

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
   int column;

   Token(TokenType type, string lexeme, int line, int column)
      : type(type), lexeme(move(lexeme)), line(line), column(column) {}
};

class LexerException : public runtime_error {
public:
   int line, column;
   LexerException(const string& message, int line, int column)
               : runtime_error(message), line(line), column(column) {}
};

vector<Token> lex(const string& source);
