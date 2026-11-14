#pragma once
class IPricePolicy
{
public:
	~IPricePolicy() = default;
	virtual int CalculatePrice(int price) const = 0;
};