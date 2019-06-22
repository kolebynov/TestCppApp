#include "stdafx.h"
#include "BaseTokenReader.h"

using namespace std;
namespace MathCalculator::Lexical
{
	ResultValue<Token> BaseTokenReader::TryReadToken(istringstream & src)
	{
		uint32_t charNumber = 0;
		string currentValue;

		while (true)
		{
			char ch = src.get();

			TokenReadingContext context { charNumber, currentValue };
			CharProcessResult charProcessResult = ProcessChar(ch, context);

			switch (charProcessResult)
			{
			case CharProcessResult::NotToken:
				src.seekg(src.tellg() - static_cast<streampos>(charNumber) - 1);
				return ResultValue<Token> { false, Token() };

			case CharProcessResult::CharReaded:
				currentValue.append(1, ch);
				break;

			case CharProcessResult::TokenReaded:
			case CharProcessResult::TokenReadedWithoutLastChar:
				if (charProcessResult == CharProcessResult::TokenReadedWithoutLastChar)
				{
					src.seekg(src.tellg() - static_cast<streampos>(1));
				}
				return ResultValue<Token> { true, context.token };
			}

			charNumber++;
		}
	}
}
