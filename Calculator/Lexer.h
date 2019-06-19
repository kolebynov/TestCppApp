#pragma once
#include "Token.h"
#include <vector>

namespace MathCalculator
{
	class Lexer
	{
	public:
		std::vector<Token> GetTokens(const std::string& srcString);

	private:
		const std::string Operators = "+-/*";
		const std::string Brackets = "()";
		const std::string Whitespaces = " ";
		const std::string Digits = "1234567890";
	};
}