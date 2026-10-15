#include "Cinema.hpp"
#include<iostream>
Cinema::Cinema()
	: m_name{ "" }
{
	std::cout << "Кинотеатр создан.\n";
}

Cinema::Cinema(std::string name, int hallNumber, int seats)
	: m_name{ name }, m_hall{ hallNumber, seats }
{
	std::cout << "Кинотеатр создан.\n";
}
Cinema::~Cinema()
{
	std::cout << "*Киноеатр удален*\n";
}
void Cinema::SetFilmToHall(Film& film)
{
	m_hall.SetFilm(film);
}
void Cinema::StartFilm()
{
	m_hall.StartFilm();
}
void Cinema::StopFilm()
{
	m_hall.StopFilm();
}
void Cinema::PrintInfo()
{
	std::cout << "Название кинотеатра: " << m_name << "\n";
	m_hall.PrintInfo();
}
	