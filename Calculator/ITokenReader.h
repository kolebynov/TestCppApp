#pragma once
#include "Token.h"
#include "ResultValue.h"
#include <sstream>

namespace MathCalculator::Lexer::Abstractions
{
	class ITokenReader
	{
	public:
		virtual ResultValue<Token> TryReadToken(std::istringstream& src) = 0;
	};
}