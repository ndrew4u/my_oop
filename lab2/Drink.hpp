#pragma once
#include "IStockItem.hpp"
#include "BaseProduct.hpp"
class Drink : public BaseProduct, public IStockItem
{
private:
    int m_count;
public:
    bool IsAvailable() const override;
    void SellOne() override;
    Drink(std::string name, int price, int count);
    Drink(const Drink& other);
    Drink(Drink&& other) noexcept;
    ~Drink() override;
    int GetPrice() const override;
    std::string Describe() const override;
    std::unique_ptr<BaseProduct> Clone() const override;
};
