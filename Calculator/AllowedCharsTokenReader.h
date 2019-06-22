#pragma once
#include "BaseTokenReader.h"

namespace MathCalculator::Lexical
{
	class AllowedCharsTokenReader : public BaseTokenReader
	{
	public:
		AllowedCharsTokenReader(const std::string& allowedChars, TokenType tokenType, uint32_t maxChars);

	protected:
		CharProcessResult ProcessChar(char ch, TokenReadingContext& context) override;

	private:
		std::string _allowedChars;
		TokenType _tokenType;
		uint32_t _maxChars;
	};
}

