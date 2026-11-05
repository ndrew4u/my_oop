#pragma once
#include "BaseProduct.hpp"
class Combo : public BaseProduct
{
private:
    std::shared_ptr<BaseProduct> m_popcorn;
    std::shared_ptr<BaseProduct> m_drink;
    int m_discount{ 0 };
public:
    Combo(std::shared_ptr<BaseProduct> popcorn,
        std::shared_ptr<BaseProduct> drink,
        int discount);
    Combo(const Combo& other);
    void CopyTo(Combo& target) const;
    Combo(Combo&& other) noexcept = default;
    Combo& operator=(const Combo& other);
    Combo& operator=(Combo&& other) noexcept = default;
    ~Combo() override;
    int GetPrice() const override;
    std::string Describe() const override;
    std::unique_ptr<BaseProduct> Clone() const override;
    std::unique_ptr<Combo> ShallowCopy() const;
};