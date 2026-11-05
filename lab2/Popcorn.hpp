#pragma once
#include "BaseProduct.hpp"
class Popcorn final : public BaseProduct
{
public:
    Popcorn();
    Popcorn(std::string name, int price);
    Popcorn(const Popcorn& other);
    Popcorn(Popcorn&& other) noexcept;
    Popcorn& operator=(const Popcorn& other) = default;
    Popcorn& operator=(Popcorn&& other) noexcept = default;
    ~Popcorn() override;
    int GetPrice() const override;
    std::string Describe() const override;
    std::unique_ptr<BaseProduct> Clone() const override;
    void SetPrice(int price);
};