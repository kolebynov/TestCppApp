#pragma once
#include "ITokenReader.h"

namespace MathCalculator::Lexer
{
	class BracketReader : public Abstractions::ITokenReader
	{
	public:
		ResultValue<Token> TryReadToken(std::istringstream& src);
	};
}

