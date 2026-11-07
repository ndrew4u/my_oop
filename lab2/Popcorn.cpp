#include "BaseProduct.hpp"
#include "Popcorn.hpp"
#include <iostream>
Popcorn::Popcorn(std::string name, int price)
	: BaseProduct(name, price)
{
	std::cout << "Попкорн сделан\n";
}
Popcorn::Popcorn()
	: BaseProduct("Обычный", 100)
{
	std::cout << "Конструктор по умолчанию Popcorn\n";
}
int Popcorn::GetPrice() const
{
	return m_price;
}
Popcorn::Popcorn(const Popcorn& other)
	: BaseProduct(other)
{
	std::cout << "Конструктор копирования Popcorn\n";
}
Popcorn::Popcorn(Popcorn&& other) noexcept
	: BaseProduct{ std::move(other) }
{
	std::cout << "Конструктор перемещенния Popcorn\n";
}
Popcorn::~Popcorn()
{
	std::cout << "Деструктор Popcorn\n";
}
std::unique_ptr<BaseProduct> Popcorn::Clone() const
{
	return std::make_unique<Popcorn>(*this);
}
std::string Popcorn::Describe() const
{
	return "Тип: Попкорн\n" + BaseProduct::Describe();
}