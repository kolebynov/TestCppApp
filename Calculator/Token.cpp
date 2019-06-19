#include "stdafx.h"
#include "Token.h"

namespace MathCalculator
{
	Token::Token(TokenType type, std::string value)
	{
		_type = type;
		_value = value;
	}
}