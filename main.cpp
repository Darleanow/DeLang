#include <iostream>
#include <sstream>
#include "Lexer/Lexer.h"

int main() {
    std::cout << "DeLang REPL. Enter 'exit' to quit." << std::endl;

    std::string input;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "exit") {
            break;
        }

        // Create a lexer instance
        Lexer lexer(input);

        // Tokenize the input
        while (lexer.has_more_tokens()) {
            lexer.next_token();
        }

        // Get the tokens and print them
        std::vector<Token> tokens = lexer.get_tokens();
        for (const auto& token : tokens) {
            std::cout << "Type: " << static_cast<int>(token.m_type) << ", Lexeme: " << token.m_lexeme << std::endl;
        }
    }

    return 0;
}
