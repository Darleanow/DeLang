#pragma once

#include <fstream>
#include <sstream>
#include <iostream>

#include "../utils/Token.h"

// A lexer is half a parser, or persay a component of a parser, for strive for simplicity, and by convention
// We make a whole class for the lexer, to separate the AST building parts and Computing tokens (which is done in parser)
// Or an executor

class Lexer 
{
public:
	// Direct input
	Lexer(const std::string& source);

	// File input
	/*Lexer(const std::filesystem::path& file_path);*/
	void next_token();
	bool has_more_tokens() const;
	std::vector<Token> get_tokens();
private:
	std::string source;
	size_t position;
	std::vector<Token> tokens;

	TokenTypes determine_token_type(const std::string& matchedText);
	void skip_white_space();
};