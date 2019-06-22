#pragma once

namespace MathCalculator::Parsing::Abstractions
{
	class Expression
	{
	public:
		virtual double Evaluate() = 0;
	};
}
