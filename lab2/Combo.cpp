#include "Combo.hpp"
#include <iostream>
Combo::Combo(std::shared_ptr<BaseProduct> popcorn,
    std::shared_ptr<BaseProduct> drink,
    int discount)
    : BaseProduct("Комбо-набор", 0),
    m_popcorn{ popcorn },
    m_drink{ drink },
    m_discount{ discount }
{
    std::cout << "Combo constructor\n";
}
Combo::Combo(const Combo& other)
    : BaseProduct(other),
    m_popcorn{ other.m_popcorn->Clone() },
    m_drink{ other.m_drink->Clone() },
    m_discount{ other.m_discount }
{
    std::cout << "Combo copy constructor\n";
}
Combo& Combo::operator=(const Combo& other)
{
    if (this == &other)
        return *this;

    BaseProduct::operator=(other);

    m_popcorn = other.m_popcorn->Clone();
    m_drink = other.m_drink->Clone();
    m_discount = other.m_discount;

    return *this;
}
Combo::~Combo()
{
    std::cout << "Combo destructor\n";
}
int Combo::GetPrice() const
{
    return m_popcorn->GetPrice()
        + m_drink->GetPrice()
        - m_discount;
}
std::string Combo::Describe() const
{
    return "Комбо: " + m_popcorn->GetName()
        + " + " + m_drink->GetName()
        + ", цена: " + std::to_string(GetPrice());
}
void Combo::CopyTo(Combo& target) const
{
    target = *this;
    std::cout << "Копирование комбо завершено\n";
}
std::unique_ptr<BaseProduct> Combo::Clone() const
{
    return std::make_unique<Combo>(*this);
}
std::unique_ptr<Combo> Combo::ShallowCopy() const
{
    return std::make_unique<Combo>(
        m_popcorn, m_drink, m_discount
    );
}