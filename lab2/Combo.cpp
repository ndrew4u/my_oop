#include "Combo.hpp"
#include <iostream>
#include <utility>
Combo::Combo(std::string name, std::shared_ptr<BaseProduct> popcorn, std::shared_ptr<BaseProduct> drink, int discount)
    : BaseProduct(name, 0),
    m_popcorn{ popcorn },
    m_drink{ drink },
    m_discount{ discount }
{
    std::cout << "Конструктор Combo\n";
}
Combo::Combo(const Combo& other)
    : BaseProduct(other), m_popcorn{ other.m_popcorn->Clone() }, m_drink{ other.m_drink->Clone() }, m_discount{ other.m_discount }
{
    std::cout << "Конструктор копирования Combo\n";
}
Combo::Combo(Combo&& other) noexcept
    : BaseProduct(std::move(other)), m_popcorn{ std::move(other.m_popcorn) }, m_drink{ std::move(other.m_drink) }, m_discount{ other.m_discount }
{
    std::cout << "Конструктор перемещения Combo\n";
}
Combo& Combo::operator=(const Combo& other)
{
    if (this != &other)
    {
        BaseProduct::operator=(other);
        m_popcorn = std::shared_ptr<BaseProduct>(other.m_popcorn->Clone());
        m_drink = std::shared_ptr<BaseProduct>(other.m_drink->Clone());
        m_discount = other.m_discount;
    }
    return *this;
}
Combo::~Combo()
{
    std::cout << "Деструктор Combo\n";
}
int Combo::GetPrice() const
{
    return m_popcorn->GetPrice() + m_drink->GetPrice() - m_discount;
}
std::string Combo::Describe() const
{
    return "Тип: Комбо\nНазвание: " + m_name + "\n\nПопкорн:\n" + m_popcorn->Describe() + "\n\nНапиток:\n" + m_drink->Describe()
        + "\n\nСкидка: " + std::to_string(m_discount)
        + "\nИтоговая цена: " + std::to_string(GetPrice());
}
std::unique_ptr<BaseProduct> Combo::Clone() const
{
    return std::make_unique<Combo>(*this);
}
