#include "stdafx.h"
#include "Lexer.h"

using namespace std;
using namespace MathCalculator::Lexer::Abstractions;
namespace MathCalculator::Lexer
{
	Lexer::Lexer(const std::vector<Abstractions::ITokenReader*>& tokenReaders,
		Abstractions::ITokenReader* whitespaceTokenReader)
	{
		_tokenReaders = tokenReaders;
		_whitespaceTokenReader = whitespaceTokenReader;
	}

	vector<Token> Lexer::GetTokens(const string & srcString)
	{
		vector<Token> tokens;
		istringstream iss(srcString);

		while (iss.tellg() != static_cast<int32_t>(string::npos))
		{
			ResultValue<Token> res;

			for (ITokenReader* reader : _tokenReaders)
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
					throw exception(("Unexpected character '" + string(1, (char)iss.peek()) + "' at position '" + to_string(iss.tellg()) + "'").c_str());
				}
			}
		}

		return tokens;
	}
}
