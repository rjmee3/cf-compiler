// ast.hpp
#pragma once
#include <memory>
#include <variant>
#include "lexer.hpp"

using namespace std;

enum class ExprType { Binary, Literal, Grouping };

struct Expr {
   virtual ~Expr() = default;
};

struct LiteralExpr : public Expr {
   int value;
   explicit LiteralExpr(int value) : value(value) {}
};

struct GroupingExpr : public Expr {
   shared_ptr<Expr> expression;
   explicit GroupingExpr(shared_ptr<Expr> expression) : expression(move(expression)) {}
};

struct BinaryExpr : public Expr {
   shared_ptr<Expr> left;
   Token op;
   shared_ptr<Expr> right;

   BinaryExpr(shared_ptr<Expr> left, Token op, shared_ptr<Expr> right)
           : left(move(left)), op(move(op)), right(move(right)) {}
};
