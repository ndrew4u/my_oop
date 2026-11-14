#include "Drink.hpp"
#include <iostream>
#include <utility>
Drink::Drink(std::string name, int price, int count)
    : BaseProduct(name, price), m_count{count}
{
    std::cout << "Конструктор Drink\n";
}
Drink::Drink(const Drink& other)
    : BaseProduct(other), m_count{other.m_count}
{
    std::cout << "Конструктор копирования Drink\n";
}
Drink::Drink(Drink&& other) noexcept
    : BaseProduct(std::move(other)), m_count{other.m_count}
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
bool Drink::IsAvailable() const
{
    if (m_count > 0) { return true; }
    else return false;
}
void Drink::SellOne()
{
    if (m_count > 0)
    {
        --m_count;
        std::cout << "Успешная продажа!\n";
    }
    else std::cout << "Напитков нет!\n";
}