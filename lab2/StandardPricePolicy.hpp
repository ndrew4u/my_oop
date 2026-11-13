#pragma once
#include "IPricePolicy.hpp"
class StandardPricePolicy : public IPricePolicy
{
public:
	int CalculatePrice(int price) const override;
};