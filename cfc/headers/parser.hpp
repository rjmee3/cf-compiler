//parser.hpp
#pragma once
#include "ast.hpp"
#include "lexer.hpp"

using namespace std;

class Parser {
public:
   explicit Parser(vector<Token> tokens);
   shared_ptr<Expr> parse();

private:
   const vector<Token> tokens;
   size_t current = 0;

   shared_ptr<Expr> expression();
   shared_ptr<Expr> term();
   shared_ptr<Expr> factor();
   shared_ptr<Expr> primary();

   bool match(TokenType type);
   Token advance();
   Token peek();
   bool isAtEnd();
};
