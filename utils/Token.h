#pragma once

#include <string>
#include <vector>

#include "tokens_types.h"

// INFORMATIONS:
// By design, we'll use an left Top to bottom parsing, hence we don't need the line number/column, but it could be cool 
// for debugging !
class Token
{
public:
	TokenTypes m_type;
	std::string m_lexeme; // A lexeme is a keyword, example "say"

	Token(TokenTypes type, std::string lexeme);

	// TODO: Remove this, just for fun and debugging
	std::string toString() const;
};