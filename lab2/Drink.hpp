#pragma once
#include "BaseProduct.hpp"
class Drink : public BaseProduct
{
public:
    Drink(std::string name, int price);
    Drink(const Drink& other) = default;
    Drink(Drink&& other) noexcept = default;
    Drink& operator=(const Drink& other) = default;
    Drink& operator=(Drink&& other) noexcept = default;
    ~Drink() override;
    int GetPrice() const override;
    std::string Describe() const override;
    std::unique_ptr<BaseProduct> Clone() const override;
    void SetPrice(int price);
};