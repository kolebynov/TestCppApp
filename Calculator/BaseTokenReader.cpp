#include "stdafx.h"
#include "BaseTokenReader.h"

using namespace std;
namespace MathCalculator::Lexer
{
	ResultValue<Token> BaseTokenReader::TryReadToken(istringstream & src)
	{
		uint32_t charNumber = 0;
		string currentValue;

		while (true)
		{
			char ch = (char)src.get();

			TokenReadingContext context { charNumber, currentValue };
			CharProcessResult charProcessResult = ProcessChar(ch, context);

			switch (charProcessResult)
			{
			case CharProcessResult::NotTokenChar:
				src.seekg(src.tellg() - (streampos)charNumber - 1);
				return ResultValue<Token> { false, Token() };
			case CharProcessResult::TokenChar:
				currentValue.append(1, ch);
				break;
			case CharProcessResult::TokenReaded:
				return ResultValue<Token> { true, context.token };
			}
		} 
	}
}
