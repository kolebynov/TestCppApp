#include "stdafx.h"
#include "BracketReader.h"
#include <string>

using namespace std;

namespace MathCalculator::Lexer
{
	ResultValue<Token> BracketReader::TryReadToken(istringstream& src)
	{
		char ch = (char)src.peek();

		if (ch == '(' || ch == ')')
		{
			src.get();
			return ResultValue<Token> { true, Token(TokenType::Bracket, string(1, ch)) };
		}

		return ResultValue<Token> { false, Token() };
	}
}
