// interpreter.cpp
#include "interpreter.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;

int evaluate(const shared_ptr<Expr>& expr) {
   if (auto lit = dynamic_cast<LiteralExpr*>(expr.get())) {
      return lit->value;
   }

   if (auto group = dynamic_cast<GroupingExpr*>(expr.get())) {
      return evaluate(group->expression);
   }

   if (auto binary = dynamic_cast<BinaryExpr*>(expr.get())) {
      int left = evaluate(binary->left);
      int right = evaluate(binary->right);

      switch (binary->op.type) {
         case TokenType::PLUS:  return left + right;
         case TokenType::MINUS: return left - right;
         case TokenType::STAR:  return left * right;
         case TokenType::SLASH:
            if (right == 0) throw runtime_error("Division by zero.");
            return left / right;
         default:
            throw runtime_error("Unknown binary operator.");
      }
   }

   throw runtime_error("Unknown expression type.");
}