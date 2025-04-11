// parser.cpp
#include "parser.hpp"
#include <stdexcept>

using namespace std;

Parser::Parser(vector<Token> tokens) : tokens(move(tokens)) {}

shared_ptr<Expr> Parser::parse() {
   return expression();
}

shared_ptr<Expr> Parser::expression() {
   return term();
}

shared_ptr<Expr> Parser::term() {
   auto expr = factor();
   while (match(TokenType::PLUS) || match(TokenType::MINUS)) {
      Token op = tokens[current - 1];
      auto right = factor();
      expr = make_shared<BinaryExpr>(expr, op, right);
   }
   return expr;
}

shared_ptr<Expr> Parser::factor() {
   auto expr = primary();
   while (match(TokenType::STAR) || match(TokenType::SLASH)) {
      Token op = tokens[current - 1];
      auto right = primary();
      expr = make_shared<BinaryExpr>(expr, op, right);
   }
   return expr;
}

shared_ptr<Expr> Parser::primary() {
   if (match(TokenType::NUMBER)) {
      int value = stoi(tokens[current - 1].lexeme);
      return make_shared<LiteralExpr>(value);
   }

   if (match(TokenType::LPAREN)) {
      auto expr = expression();
      match(TokenType::RPAREN); // basic error skipping
      return make_shared<GroupingExpr>(expr);
   }

   throw ParserException("Expected expression or number.", tokens[current].line, tokens[current].column);
}

bool Parser::match(TokenType type) {
   if (isAtEnd()) return false;
   if (peek().type != type) return false;
   advance();
   return true;
}

Token Parser::advance() {
   if (!isAtEnd()) current++;
   return tokens[current - 1];
}

Token Parser::peek() {
   return tokens[current];
}

bool Parser::isAtEnd() {
   return tokens[current].type == TokenType::EOF_TOKEN;
}
