// lexer.cpp
#include "lexer.hpp"
#include <cctype>

using namespace std;

static vector<Token> tokens;
static string::const_iterator current;
static string::const_iterator start;
static int line = 1;

static void addToken(TokenType type, const string& source) {
   tokens.emplace_back(type, string(start, current), line);
}

static void scanToken(const string& source) {
   char c = *current++;
   switch (c) {
      case '+': addToken(TokenType::PLUS,   source); break;
      case '-': addToken(TokenType::MINUS,  source); break;
      case '*': addToken(TokenType::STAR,   source); break;
      case '/': addToken(TokenType::SLASH,  source); break;
      case '(': addToken(TokenType::LPAREN, source); break;
      case ')': addToken(TokenType::RPAREN, source); break;

      default:
         if (isdigit(c)) {
            while (current != source.end() && isdigit(*current)) current++;
            addToken(TokenType::NUMBER, source);
         }
         break;
   }
}

vector<Token> lex(const string& source) {
   tokens.clear();
   current = source.begin();
   while (current != source.end()) {
      start = current;
      scanToken(source);
   }

   tokens.emplace_back(TokenType::EOF_TOKEN, "", line);
   return tokens;
}
