#include "Token.h"

Token::Token(TokenTypes type, std::string lexeme) : m_type(type), m_lexeme(std::move(lexeme)) {}

std::string Token::toString() const {
	return "Type: " + std::to_string(static_cast<int>(m_type)) + " || Lexeme: " + m_lexeme;
}