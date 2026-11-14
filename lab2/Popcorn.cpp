#include "BaseProduct.hpp"
#include "Popcorn.hpp"
#include "OutOfStockError.hpp"
#include <iostream>
Popcorn::Popcorn(std::string name, int price, int count)
	: BaseProduct(name, price), m_count{count}
{
	std::cout << "Конструктор с параметрами Popcorn\n";
}
Popcorn::Popcorn()
	: BaseProduct("Обычный", 100), m_count{10}
{
	std::cout << "Конструктор по умолчанию Popcorn\n";
}
int Popcorn::GetPrice() const
{
	return m_price;
}
Popcorn::Popcorn(const Popcorn& other)
	: BaseProduct(other), m_count{other.m_count}
{
	std::cout << "Конструктор копирования Popcorn\n";
}
Popcorn::Popcorn(Popcorn&& other) noexcept
	: BaseProduct{ std::move(other) }, m_count{other.m_count}
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
std::string Popcorn::GetName() const
{
	return "Название: " + m_name;
}
bool Popcorn::IsAvailable() const
{
	if (m_count > 0) { return true; }
	else return false;
}
void Popcorn::SellOne()
{
	if (m_count > 0)
	{
		--m_count;
		std::cout << "Успешная продажа!\n";
	}
	else throw OutOfStockError{ GetName() };;
}