#pragma once
#include <string>

class Film
{
private:
	std::string m_name;
	int m_minutes;
	int m_ageLimit;
public:
	Film();
	Film(std::string name, int minutes, int ageLimit);
	~Film();
	void PrintInfo();
	void ChangeMinutes(int NewMinutes);
	void CheckAge(int Age);
};