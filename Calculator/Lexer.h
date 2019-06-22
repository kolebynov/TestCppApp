#pragma once
#include "Token.h"
#include "ITokenReader.h"
#include <vector>

namespace MathCalculator::Lexer
{
	class Lexer
	{
	public:
		Lexer(const std::vector<Abstractions::ITokenReader*>& tokenReaders, Abstractions::ITokenReader* whitespaceTokenReader);

		std::vector<Token> GetTokens(const std::string& srcString);

	private:
		std::vector<Abstractions::ITokenReader*> _tokenReaders;
		Abstractions::ITokenReader* _whitespaceTokenReader;
	};
}