#pragma once
#include "hall.hpp"
#include<string>
#include <memory>
class Cinema
{
private:
	std::string m_name;
	Hall m_hall;
public:
	Cinema();
	Cinema(std::string name, int hallNumber, int seats);
	~Cinema();
	void SetFilmToHall(std::shared_ptr<Film>& film);
	void StartFilm();
	void StopFilm();
	void PrintInfo();
};