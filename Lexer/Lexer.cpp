#include <regex>
#include <iostream>
#include <unordered_map>

#include "Lexer.h"

// Token Regex Patterns
struct Pattern {
    std::regex regex;
    TokenTypes type;
};

const std::vector<Pattern> patterns= {
    // Numeric values
    {std::regex("^\\d+\\.\\d+"), TokenTypes::FLOAT},
    {std::regex("^\\d+"), TokenTypes::INT},

    // Parenthis
    {std::regex("^\\("), TokenTypes::PAREN_OPEN},
    {std::regex("^\\)"), TokenTypes::PAREN_CLOSE},

    // String literals
    {std::regex("^\".*?\""), TokenTypes::STRING},

    // Boolean literals
    {std::regex("^(true|false)"), TokenTypes::BOOLEAN},

    // Array brackets
    {std::regex("^\\["), TokenTypes::ARRAY_START},
    {std::regex("^\\]"), TokenTypes::ARRAY_END},

    // Structure symbols
    {std::regex("^\\{"), TokenTypes::BLOCK_START},
    {std::regex("^\\}"), TokenTypes::BLOCK_END},
    {std::regex("^:"), TokenTypes::ELSE_CONDITION},
    {std::regex("^\\?"), TokenTypes::CONDITION},

    // Loop and control structures
    {std::regex("^repeat"), TokenTypes::FOR_LOOP},
    {std::regex("^while"), TokenTypes::WHILE_LOOP},

    // Range operator
    {std::regex("^\\.\\."), TokenTypes::RANGE_OPERATOR},

    // Keywords for print and type declarations
    {std::regex("^say"), TokenTypes::PRINT_FUNCTION},

    // Assignment keyword
    {std::regex("^is"), TokenTypes::ASSIGNMENT_OPERATOR},

    // Operators
    {std::regex("^(\\+|-|\\*|/)"), TokenTypes::ARITHMETIC_OPERATOR},
    {std::regex("^(==|>|<|>=|<=)"), TokenTypes::RELATIONAL_OPERATOR},
    {std::regex("^(and|or)"), TokenTypes::LOGICAL_OPERATOR},

    // Function names
    {std::regex("^(lengthOf|maxOf|sumOf)"), TokenTypes::FUNCTION_NAME},

    // Comments
    {std::regex("^//.*"), TokenTypes::COMMENT},

    // Identifiers (variables, function names)
    {std::regex("^[a-zA-Z_][a-zA-Z0-9_]*"), TokenTypes::IDENTIFIER},
};

Lexer::Lexer(const std::string& source) : source(source), position(0) {}

void Lexer::next_token() {
    skip_white_space();
    std::string str = source.substr(position);

    auto matchFound = std::find_if(patterns.begin(), patterns.end(), [this, &str](const Pattern& pattern) {
        std::smatch match;
        if (std::regex_search(str, match, pattern.regex, std::regex_constants::match_continuous)) {
            tokens.push_back(Token(pattern.type, match.str(0)));
            position += match.str(0).length();
            return true;
        }
        return false;
    });

    if (matchFound == patterns.end() && position < source.length()) {
        std::cerr << "Unrecognized token: " << source[position] << " at position " << position << std::endl;
        position++; // Skip unrecognized character
    }
}

std::vector<Token> Lexer::get_tokens()
{
    return tokens;
}

void Lexer::skip_white_space() {
    position = std::find_if_not(source.begin() + position, source.end(), ::isspace) - source.begin();
}

bool Lexer::has_more_tokens() const {
    return position < source.length();
}
