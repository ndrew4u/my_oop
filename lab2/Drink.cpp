#include "Drink.hpp"
#include <iostream>
Drink::Drink(std::string name, int price)
    : BaseProduct(name, price)
{
    std::cout << "Drink constructor\n";
}
Drink::~Drink()
{
    std::cout << "Drink destructor\n";
}
int Drink::GetPrice() const
{
    return m_price;
}
std::string Drink::Describe() const
{
    return "Напиток: " + m_name +
        ", цена: " + std::to_string(GetPrice());
}
std::unique_ptr<BaseProduct> Drink::Clone() const
{
    return std::make_unique<Drink>(*this);
}
void Drink::SetPrice(int price)
{
    if (price >= 0)
        m_price = price;
}