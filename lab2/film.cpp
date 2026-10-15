#include "film.hpp"
#include <iostream>

Film::Film()
	: m_name{ "" }, m_minutes{ 0 }, m_ageLimit{ 0 }
{
	std::cout << "Фильм создан\n";
}
Film::Film(std::string name, int minutes, int ageLimit)
	: m_name{ name }, m_minutes{ minutes }, m_ageLimit{ ageLimit }
{
	std::cout << "Фильм создан\n";
}
Film::~Film()
{
	std::cout << "*Фильм удален*" << "\n";
}
void Film::PrintInfo()
{
	std::cout << "Название фильма: " << m_name << "\n";
	std::cout << "Длительность фильма (в минутах): " << m_minutes << "\n";
	std::cout << "Возрастное ограничение: " << m_ageLimit << "+" << "\n";
}
void Film::ChangeMinutes(int NewMinutes)
{
	if (NewMinutes >= 0)
	{
		m_minutes = NewMinutes;
		std::cout << "Длительность фильма изменена\n";
	}
	else
	{
		std::cout << "Ошибка! Длительность фильма не может быть отрицательной!\n";
	}
}
void Film::CheckAge(int Age)
{
	if (Age >= 18)
	{
		std::cout << "Просмотр фильма разрешен.\n";
	}
	else
	{
		std::cout << "Просмотр фильма запрещен.\n";
	}

}