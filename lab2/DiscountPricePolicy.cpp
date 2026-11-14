#include "DiscountPricePolicy.hpp"
int DiscountPricePolicy::CalculatePrice(int price) const
{
	return (price - (price * 0.1));
}
