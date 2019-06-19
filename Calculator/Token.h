#pragma once
#include "TokenType.h"
#include <string>

namespace MathCalculator
{
	class Token
	{
	public:
		Token(TokenType type, std::string value);

	private:
		TokenType _type;
		std::string _value;
	};
}

