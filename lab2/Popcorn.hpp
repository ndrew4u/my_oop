#pragma once
#include "BaseProduct.hpp"
class Popcorn final: public BaseProduct
{
public:
	Popcorn(std::string name, int price);
	Popcorn();
	int GetPrice() const override;
	Popcorn(const Popcorn& other);
	Popcorn(Popcorn&& other) noexcept;
	~Popcorn() override;
	std::unique_ptr<BaseProduct> Clone() const override;
	std::string Describe() const override;
};