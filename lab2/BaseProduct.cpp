#include "BaseProduct.hpp"
#include <iostream>
int BaseProduct::s_createdCount = 0;
BaseProduct::BaseProduct(std::string name, int price)
	: m_name{ name }, m_price{ price }
{
	++s_createdCount;
	std::cout << "Конструктор BaseProduct\n";
}
void BaseProduct::SetPrice(int price)
{
	m_price = price;
}
BaseProduct::~BaseProduct()
{
	std::cout << "Деструктор BaseProduct\n";
}
BaseProduct::BaseProduct(const BaseProduct& other)
	: m_name{other.m_name}, m_price{other.m_price}
{
	++s_createdCount;
	std::cout << "Конструктор копирования BaseProduct\n";
}
BaseProduct::BaseProduct(BaseProduct&& other) noexcept
	: m_name{ std::move(other.m_name) }, m_price{ other.m_price }
{
	++s_createdCount;
	std::cout << "Конструктор перемещения BaseProduct\n";
}
std::string BaseProduct::GetName() const
{
	return m_name;
}
int BaseProduct::GetCreatedCount()
{
	return s_createdCount;
}
std::string BaseProduct::Describe() const
{
	return "Название: " + m_name + "\nЦена: " + std::to_string(m_price);
}

