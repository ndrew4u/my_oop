#pragma once
#include"film.hpp"
class Hall
{
private:
	int m_number;
	int m_seats;
	Film* m_film;
	bool m_isFilmStarted;
public:
	Hall();
	Hall(int number, int seats);
	~Hall();
	void SetFilm(Film& film);
	void StartFilm();
	void StopFilm();
	void PrintInfo();
};