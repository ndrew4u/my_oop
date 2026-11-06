#pragma once
#include "BaseProduct.hpp"
class Drink : public BaseProduct
{
public:
    Drink(std::string name, int price);
    Drink(const Drink& other);
    Drink(Drink&& other) noexcept;
    ~Drink() override;
    int GetPrice() const override;
    std::string Describe() const override;
    std::unique_ptr<BaseProduct> Clone() const override;
};
