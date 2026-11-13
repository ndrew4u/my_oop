#pragma once
#include "IStockItem.hpp"
#include "BaseProduct.hpp"
class Popcorn final: public BaseProduct, public IStockItem
{
private:
	int m_count;
public:
	bool IsAvailable() const override;
	void SellOne() override;
	Popcorn(std::string name, int price, int count);
	Popcorn();
	int GetPrice() const override;
	Popcorn(const Popcorn& other);
	Popcorn(Popcorn&& other) noexcept;
	~Popcorn() override;
	std::unique_ptr<BaseProduct> Clone() const override;
	std::string Describe() const override;
	std::string GetName() const;
};