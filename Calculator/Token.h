#pragma once
#include "TokenType.h"
#include <string>

namespace MathCalculator::Lexer
{
	class Token
	{
	public:
		Token();
		Token(TokenType type, std::string value);

		TokenType GetType() const;
		const std::string& GetValue() const;

	private:
		TokenType _type;
		std::string _value;
	};
}

