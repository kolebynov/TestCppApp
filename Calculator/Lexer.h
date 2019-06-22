#pragma once
#include "Token.h"
#include "ITokenReader.h"
#include <vector>
#include <sstream>

namespace MathCalculator::Lexical
{
	template <class TTokenReaders>
	class Lexer
	{
	public:
		Lexer(
			const TTokenReaders& readers,
			const std::shared_ptr<Abstractions::ITokenReader>& whitespaceTokenReader)
		{
			_tokenReaders = readers;
			_whitespaceTokenReader = whitespaceTokenReader;
		}

		std::vector<Token> GetTokens(const std::string& srcString)
		{
			std::vector<Token> tokens;
			std::istringstream iss(srcString);

			while (iss.tellg() != static_cast<int32_t>(std::string::npos))
			{
				ResultValue<Token> res;

				for (const std::shared_ptr<Abstractions::ITokenReader>& reader : _tokenReaders)
				{
					res = reader->TryReadToken(iss);
					if (res.success)
					{
						tokens.push_back(res.value);
						break;
					}
				}

				if (!res.success)
				{
					res = _whitespaceTokenReader->TryReadToken(iss);
					if (!res.success)
					{
						throw std::exception(("Unexpected character '" + std::string(1, (char)iss.peek()) + "' at position '" + to_string(iss.tellg()) + "'").c_str());
					}
				}
			}

			return tokens;
		}

	private:
		TTokenReaders _tokenReaders;
		std::shared_ptr<Abstractions::ITokenReader> _whitespaceTokenReader;
	};
}