#include "Drink.hpp"
#include <iostream>
#include <utility>
Drink::Drink(std::string name, int price)
    : BaseProduct(name, price)
{
    std::cout << "Конструктор Drink\n";
}
Drink::Drink(const Drink& other)
    : BaseProduct(other)
{
    std::cout << "Конструктор копирования Drink\n";
}
Drink::Drink(Drink&& other) noexcept
    : BaseProduct(std::move(other))
{
    std::cout << "Конструктор перемещения Drink\n";
}
Drink::~Drink()
{
    std::cout << "Деструктор Drink\n";
}
int Drink::GetPrice() const
{
    return m_price;
}
std::string Drink::Describe() const
{
    return "Тип: Напиток\nНазвание: " + BaseProduct::Describe();
}
std::unique_ptr<BaseProduct> Drink::Clone() const
{
    return std::make_unique<Drink>(*this);
}