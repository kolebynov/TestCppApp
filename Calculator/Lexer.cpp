#include "stdafx.h"
#include "Lexer.h"

using namespace std;
namespace MathCalculator
{
	vector<Token> Lexer::GetTokens(const string & srcString)
	{
		vector<Token> result;
		
		string currentNumber;
		bool isNumber = false;
		for (int pos = 0; pos < srcString.length(); ++pos)
		{
			char ch = srcString[pos];

			if (Digits.find(ch) != string::npos)
			{
				if (!isNumber)
				{
					currentNumber.clear();
				}

				currentNumber.append(1, ch);
				isNumber = true;
				continue;
			}

			if (isNumber)
			{
				result.push_back(Token(TokenType::Number, currentNumber));
				isNumber = false;
			}

			if (Brackets.find(ch) != string::npos)
			{
				result.push_back(Token(TokenType::Bracket, string(1, ch)));
				continue;
			}

			if (Operators.find(ch) != string::npos)
			{
				result.push_back(Token(TokenType::Operator, string(1, ch)));
				continue;
			}

			if (Whitespaces.find(ch) != string::npos)
			{
				continue;
			}

			throw exception(("Unexpected character '" + string(1, ch) + "' at position '" + to_string(pos) + "'").c_str());
		}

		return result;
	}
}
