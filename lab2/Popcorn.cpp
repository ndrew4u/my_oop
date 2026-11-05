#include "Popcorn.hpp"
#include <iostream>
#include <utility>
Popcorn::Popcorn()
    : BaseProduct("Попкорн", 0)
{
    std::cout << "Popcorn default constructor\n";
}
Popcorn::Popcorn(std::string name, int price)
    : BaseProduct(name, price)
{
    std::cout << "Popcorn constructor\n";
}
Popcorn::Popcorn(const Popcorn& other)
    : BaseProduct(other)
{
    std::cout << "Popcorn copy constructor\n";
}
Popcorn::Popcorn(Popcorn&& other) noexcept
    : BaseProduct(std::move(other))
{
    std::cout << "Popcorn move constructor\n";
}
Popcorn::~Popcorn()
{
    std::cout << "Popcorn destructor\n";
}
int Popcorn::GetPrice() const
{
    return m_price;
}
std::string Popcorn::Describe() const
{
    return BaseProduct::Describe() + " (попкорн)";
}
std::unique_ptr<BaseProduct> Popcorn::Clone() const
{
    return std::make_unique<Popcorn>(*this);
}
void Popcorn::SetPrice(int price)
{
    if (price >= 0)
        m_price = price;
}