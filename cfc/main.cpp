// main.cpp
#include "lexer.hpp"
#include "parser.hpp"
#include "ast.hpp"
#include <iostream>

using namespace std;

int main() {
   string input = "1 + 2 * (3 - 4)";
   auto tokens = lex(input);

   Parser parser(tokens);
   auto ast = parser.parse();

   cout << "Parsed successfully.\n";
   return 0;
}