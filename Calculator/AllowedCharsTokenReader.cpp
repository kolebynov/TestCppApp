#include "stdafx.h"
#include "AllowedCharsTokenReader.h"

using namespace std;
namespace MathCalculator::Lexer
{
	AllowedCharsTokenReader::AllowedCharsTokenReader(const string & allowedChars, TokenType tokenType, uint32_t maxChars)
	{
		_allowedChars = allowedChars;
		_tokenType = tokenType;
		_maxChars = maxChars;
	}

	BaseTokenReader::CharProcessResult AllowedCharsTokenReader::ProcessChar(char ch, TokenReadingContext & context)
	{
		if (_allowedChars.find(ch) != string::npos)
		{
			if (context.charNumber == _maxChars - 1)
			{
				context.token = Token(_tokenType, context.currentValue + ch);
				return CharProcessResult::TokenReaded;
			}

			return CharProcessResult::CharReaded;
		}

		if (context.charNumber > 0)
		{
			context.token = Token(_tokenType, context.currentValue);
			return CharProcessResult::TokenReadedWithoutLastChar;
		}

		return CharProcessResult::NotToken;
	}
}
