#pragma once

namespace MathCalculator
{
	template <class T>
	struct ResultValue
	{
		const bool success;
		const T value;
	};
}