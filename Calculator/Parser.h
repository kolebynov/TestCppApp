#pragma once
#include "Expression.h"
#include <memory>

namespace MathCalculator::Parsing
{
	class Parser
	{
	public:
		template <class TTokens>
		std::shared_ptr<Abstractions::Expression> BuildExpression(const TTokens& tokens)
		{
			
		}
	};
}