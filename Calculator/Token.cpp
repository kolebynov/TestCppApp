#include "stdafx.h"
#include "Token.h"

namespace MathCalculator::Lexical
{
	Token::Token()
	{
	}

	Token::Token(TokenType type, const std::string& value)
	{
		_type = type;
		_value = value;
	}

	TokenType Token::GetType() const
	{
		return _type;
	}

	const std::string & Token::GetValue() const
	{
		return _value;
	}
}