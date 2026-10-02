#pragma once
#include "hall.hpp"
#include<string>
class Cinema
{
private:
	std::string m_name;
	Hall m_hall;
public:
	Cinema();
	Cinema(std::string name, int hallNumber, int seats);
	~Cinema();
	void SetFilmToHall(Film& film);
	void StartFilm();
	void StopFilm();
	void PrintInfo();
};