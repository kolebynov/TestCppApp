#pragma once
#include "ITokenReader.h"

namespace MathCalculator
{
	class BracketReader : public ITokenReader
	{
	public:
		ResultValue<Token> TryReadToken(std::istringstream& src);
	};
}

