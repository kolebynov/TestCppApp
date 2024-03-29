#pragma once
#include "ITokenReader.h"

namespace MathCalculator::Lexical
{
	class BaseTokenReader : public Abstractions::ITokenReader
	{
		class TokenReadingContext;
		enum class CharProcessResult;

	public:
		ResultValue<Token> TryReadToken(std::istringstream& src) override;

	protected:
		virtual CharProcessResult ProcessChar(char ch, TokenReadingContext& context) = 0;

	protected:
		struct TokenReadingContext
		{
		public:
			const uint32_t charNumber;
			const std::string& currentValue;
			Token token;
		};

		enum class CharProcessResult
		{
			NotToken,
			CharReaded,
			TokenReaded,
			TokenReadedWithoutLastChar
		};
	};
}

