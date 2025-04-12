// main.cpp
#include "lexer.hpp"
#include "parser.hpp"
#include "interpreter.hpp"
#include <iostream>

using namespace std;

int main() {
   string input = "1 + 2 * ((3 - 4) * 5 - 6)";
   auto tokens = lex(input);

   Parser parser(tokens);
   auto ast = parser.parse();

   try {
      int result = evaluate(ast);
      cout << "Result: " << result << "\n";
   } catch (const exception& e) {
      cerr << "Evaluation error: " << e.what() << "\n";
   }

   return 0;
}