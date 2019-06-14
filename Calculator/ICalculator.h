#pragma once

#define VIRTUAL(def) virtual def = 0;

class ICalculator
{
	VIRTUAL(double Calculate())
};