#include "Hall.hpp"
#include<iostream>
Hall::Hall()
    : m_number{ 0 }, m_seats{ 0 }, m_film{}, m_isFilmStarted{false}
{
    std::cout << "Кинозал создан\n";
}
Hall::Hall(int number, int seats)
{
    if (number <= 0 || seats <= 0)
    {
        std::cout << "Номер зала и количество сидений должны быть больше 0!\n";
        m_number = 0;
        m_seats = 0;
    }
    else
    {
        m_number = number;
        m_seats = seats;
    }
    m_film.reset();
    m_isFilmStarted = false;
    std::cout << "*Зал создан*\n";
}
Hall::~Hall()
{
    std::cout << "*Зал удален*\n";
}
void Hall::SetFilm(std::shared_ptr<Film>& film)
{
    m_film = film;
    std::cout << "Фильм назначен залу.\n";
}
void Hall::StartFilm()
{
    if (std::shared_ptr<Film> film = m_film.lock())
    {
        m_isFilmStarted = true;
        std::cout << "Фильм запущен.\n";
    }
    else { std::cout << "Фильм не назначен залу.\n"; return; }
}
void Hall::StopFilm()
{
    if (m_isFilmStarted == false)
    {
        std::cout << "Фильм уже остановлен.\n";
    }
    else
    {
        m_isFilmStarted = false;
        std::cout << "Фильм остановлен.\n";
    }
}
void Hall::PrintInfo()
{
    std::cout << "Номер зала: " << m_number << "\n";
    std::cout << "Количество мест: " << m_seats << "\n";
    if (std::shared_ptr<Film> film = m_film.lock())
    {
        std::cout << "Фильм в зале:\n";
        film->PrintInfo();
    }
    else
    {
        std::cout << "Фильм не назначен.\n";
    }
}