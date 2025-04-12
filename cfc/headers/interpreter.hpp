// interpreter.hpp
#pragma once
#include "ast.hpp"

using namespace std;

int evaluate(const shared_ptr<Expr>& expr);
