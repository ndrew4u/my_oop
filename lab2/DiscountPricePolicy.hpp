#pragma once
#include "IPricePolicy.hpp"
class DiscountPricePolicy : public IPricePolicy
{
public:
	int CalculatePrice(int price) const override;
};