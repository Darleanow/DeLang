enum class TokenTypes
{
	PROGRAM = 0, // A program is a list of statements
	STATEMENT = 1, // A statement is a variable decl, a typed variable decl, a condition, a loop, an operation, a function call, or a comment
	VAR_DECL = 2, // A var decl is an identifier (is), and an expression
	TYPE_DECL = 3, // A type decl is a type, ":", an identifier, and an expression

	EXPRESSION = 4, // Can be a literal, an identifier, an operation, or a function call

	TYPE = 5, // A type can be string, int, float, boolean, or array
	NUMBER = 6, // A number is a int or a float
	INT = 7,
	FLOAT = 8,
	STRING = 9, // A string is a list of chars between "
	BOOLEAN = 10, // A boolean is true or false
	ARRAY = 11, // An array is a list of expressions in between brackets

	CONDITION = 12, // Contains an expression, a statement, might have an else if condition, might have an else condition
	ELSE_IF_CONDITION = 13, // Contains an expression, which is a statement
	ELSE_CONDITION = 14, // Contains a statement

	LOOP = 15, // Can be a while or a for loop
	RANGE = 16, // Is number1..number2
	FOR_LOOP = 17, // Contains "repeat" + an identifier + -> + a range, and statements
	WHILE_LOOP = 18, // Contains "while", an expression, and statements

	OPERATION = 19, // Contains an expression, an operator and an expression
	OPERATOR = 20, // Can be +,-,*,/, ==, <, >, <=, >=, and, or //TODO: Implement NOR,XOR,NAND

	FUNCTION_CALL = 21, // Contains a fonction name, an expression, with parameters (expression)
	FONCTION_NAME = 22, // Examples lengthOf, maxOf, sumOf

	PRINT_FUNCTION = 23, // "say" expression

	COMMENT = 24, // "//" , TODO: /* * */ for blocks

	IDENTIFIER = 25, // Matches any char, any number ([a-zA-Z_][a-zA-Z0-9_]*)
};