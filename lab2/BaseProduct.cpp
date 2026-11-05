#include "BaseProduct.hpp"
#include <iostream>
#include <utility>
int BaseProduct::s_createdCount = 0;
BaseProduct::BaseProduct(std::string name, int price)
    : m_name{ std::move(name) }, m_price{ price }
{
    ++s_createdCount;
    std::cout << "BaseProduct constructor\n";
}
BaseProduct::BaseProduct(const BaseProduct& other)
    : m_name{ other.m_name }, m_price{ other.m_price }
{
    ++s_createdCount;
    std::cout << "BaseProduct copy constructor\n";
}
BaseProduct::BaseProduct(BaseProduct&& other) noexcept
    : m_name{ std::move(other.m_name) },
    m_price{ other.m_price }
{
    ++s_createdCount;
    std::cout << "BaseProduct move constructor\n";
}
BaseProduct::~BaseProduct()
{
    std::cout << "BaseProduct destructor\n";
}
std::string BaseProduct::Describe() const
{
    return "Товар: " + m_name +
        ", цена: " + std::to_string(GetPrice());
}
const std::string& BaseProduct::GetName() const
{
    return m_name;
}
int BaseProduct::GetCreatedCount()
{
    return s_createdCount;
}