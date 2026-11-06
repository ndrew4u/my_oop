#pragma once
#include "BaseProduct.hpp"
class Combo : public BaseProduct
{
private:
    std::shared_ptr<BaseProduct> m_popcorn;
    std::shared_ptr<BaseProduct> m_drink;
    int m_discount;
public:
    Combo(std::string name,
        std::shared_ptr<BaseProduct> popcorn,
        std::shared_ptr<BaseProduct> drink,
        int discount);
    Combo(const Combo& other);
    Combo(Combo&& other) noexcept;
    Combo& operator=(const Combo& other);
    Combo& operator=(Combo&& other) noexcept = default;
    ~Combo() override;
    int GetPrice() const override;
    std::string Describe() const override;
    std::unique_ptr<BaseProduct> Clone() const override;
};
