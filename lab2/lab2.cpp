#include "Cinema.hpp"
#include "film.hpp"
#include "hall.hpp"
#include<iostream>
#include<locale.h>
int main()
{
    setlocale(LC_ALL, "RUS");
    Film film("Интерстеллар", 169, 12);
    film.ChangeMinutes(120);
    film.ChangeMinutes(-5);
    std::cout << "\n";
    {
        Cinema cinema("Аврора", 1, 100);
        cinema.StartFilm();
        cinema.SetFilmToHall(film);
        cinema.StartFilm();
        cinema.PrintInfo();
        cinema.StopFilm();
    }
    std::cout << "\nКинотеатр уже удален, а фильм еще существует:\n";
    film.PrintInfo();
    std::cout << "\nУказатель:\n";
    Film* filmPointer = &film;
    filmPointer->PrintInfo();
    std::cout << "\nСсылка:\n";
    Film& filmReference = film;
    filmReference.PrintInfo();
    std::cout << "\nДинамический объект:\n";
    Film* dynamicFilm = new Film("Матрица", 136, 16);
    dynamicFilm->PrintInfo();
    delete dynamicFilm;
    dynamicFilm = nullptr;
    std::cout << "\nДинамический массив объектов:\n";
    Film* filmArray = new Film[2];
    filmArray[0].ChangeMinutes(100);
    filmArray[1].ChangeMinutes(120);
    delete[] filmArray;
    std::cout << "\nМассив динамических объектов:\n";
    Film** dynamicFilmArray = new Film * [2];
    dynamicFilmArray[0] = new Film("Дюна", 155, 12);
    dynamicFilmArray[1] = new Film("Начало", 148, 12);
    dynamicFilmArray[0]->PrintInfo();
    dynamicFilmArray[1]->PrintInfo();
    delete dynamicFilmArray[0];
    delete dynamicFilmArray[1];
    delete[] dynamicFilmArray;
    return 0;
}