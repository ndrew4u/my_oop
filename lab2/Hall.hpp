#pragma once
#include"film.hpp"
#include <memory>
class Hall
{
private:
	int m_number;
	int m_seats;
	std::weak_ptr<Film> m_film;
	bool m_isFilmStarted;
public:
	Hall();
	Hall(int number, int seats);
	~Hall();
	void SetFilm(std::shared_ptr<Film>& film);
	void StartFilm();
	void StopFilm();
	void PrintInfo();
};