#pragma once
#include <string>
#include <memory>
class BaseProduct
{
protected:
	std::string m_name;
	int m_price;
	BaseProduct(std::string name, int price);
private:
	static int s_createdCount;
public:
	virtual int GetPrice() const = 0;
	void SetPrice(int price);
	virtual ~BaseProduct();
	BaseProduct(const BaseProduct& other);
	BaseProduct(BaseProduct&& other) noexcept;
	BaseProduct& operator=(const BaseProduct& other) = default;
	BaseProduct& operator=(BaseProduct&& other) noexcept = default;
	std::string GetName() const;
	static int GetCreatedCount();
	virtual std::string Describe() const;
	virtual std::unique_ptr<BaseProduct> Clone() const = 0;
};