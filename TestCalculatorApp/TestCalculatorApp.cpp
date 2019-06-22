// TestCalculatorApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "../Calculator/Lexer.h"
#include "../Calculator/AllowedCharsTokenReader.h"

using namespace std;
using namespace MathCalculator;
using namespace MathCalculator::Lexer;
using namespace MathCalculator::Lexer::Abstractions;

int main()
{
	vector<ITokenReader*> readers;
	readers.push_back(new AllowedCharsTokenReader("()", TokenType::Bracket, 1));
	readers.push_back(new AllowedCharsTokenReader("+-/*", TokenType::Operator, 1));
	readers.push_back(new AllowedCharsTokenReader("1234567890", TokenType::Number, numeric_limits<uint32_t>::max()));
	MathCalculator::Lexer::Lexer lexer(readers, new AllowedCharsTokenReader(" ", TokenType::Whitespace, numeric_limits<uint32_t>::max()));
	auto tokens = lexer.GetTokens("(231+ 2)-3");
	int a = 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
