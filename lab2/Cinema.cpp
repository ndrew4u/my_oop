#include "Cinema.hpp"
#include <iostream>
#include <utility>
Cinema::Cinema()
    : m_name{ "" }, m_hall{}
{
    std::cout << "Кинотеатр создан.\n";
}
Cinema::Cinema(std::string name, int hallNumber, int seats)
    : m_name{ std::move(name) },
    m_hall{ hallNumber, seats }
{
    std::cout << "Кинотеатр создан.\n";
}
Cinema::~Cinema()
{
    std::cout << "*Кинотеатр удален*\n";
}
void Cinema::SetFilmToHall(std::shared_ptr<Film>& film)
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
    std::cout << "Название кинотеатра: "
        << m_name << "\n";

    m_hall.PrintInfo();
}