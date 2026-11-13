#pragma once
class IStockItem
{
public:
	virtual ~IStockItem() = default;
	virtual bool IsAvailable() const = 0;
	virtual void SellOne() = 0;
};