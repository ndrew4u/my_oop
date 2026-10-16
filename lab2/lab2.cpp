#include "Cinema.hpp"
#include "film.hpp"
#include "hall.hpp"
#include<iostream>
#include<locale.h>
#include<memory>
int main()
{
    setlocale(LC_ALL, "RUS");
    {
        std::cout << "Передача владения:\n";
        std::unique_ptr<Film> film = std::make_unique<Film>("Начало", 148, 12);
        std::cout << "До передачи:\n";
        film->PrintInfo();
        std::unique_ptr<Film> film2 = std::move(film);
        if (film == nullptr)
        {
            std::cout << "film пуст после передачи!\n";
        }
        if (film2 != nullptr)
        {
            std::cout << "film2 получил владение!\n";
            film2->PrintInfo();
        }
        film2.reset();
    }
    {
        std::shared_ptr<Film> film = std::make_shared<Film>("Интерстеллар", 169, 12);
        Cinema cinema("Кинотеатр", 1, 100);
        cinema.SetFilmToHall(film);
        std::cout << "\nДо удаления фильма:\n";
        cinema.StartFilm();
        cinema.StopFilm();
        film.reset();
        std::cout << "\nПосле удаления фильма:\n";
        cinema.StartFilm();
        cinema.PrintInfo();
    }
    std::cout << "\nУмный указатель unique_ptr:\n";
    {
        std::unique_ptr<Film> dynamicFilm = std::make_unique<Film>("Матрица", 136, 16);
        dynamicFilm->PrintInfo();
    }
    std::cout << "Вышли из блока unique_ptr\n";
    std::cout << "\nУмный указатель shared_ptr:\n";
    std::shared_ptr<Film> film1 = std::make_shared<Film>("Дюна", 155, 12);
    std::cout << "Владельцев: " << film1.use_count() << "\n";
    {
        std::shared_ptr<Film> film2 = film1;
        std::cout << "Владельцев: " << film1.use_count() << "\n";
        film2->PrintInfo();
    }
    std::cout << "Владельцев: " << film1.use_count() << "\n";
    std::cout << "\nУмный указатель weak_ptr:\n";
    std::weak_ptr<Film> ukaz;
    {
        std::shared_ptr<Film> film1 = std::make_shared<Film>("Начало", 148, 12);
        ukaz = film1;
        std::cout << "Владельцев: " << film1.use_count() << "\n";
        if (std::shared_ptr<Film> temp = ukaz.lock())
        {
            std::cout << "Фильм существует!\n";
            temp->PrintInfo();
        }
    }
    std::cout << "Вышли из блока\n";
    if (std::shared_ptr<Film> temp = ukaz.lock())
    {
        std::cout << "Фильм существует!\n";
    }
    else
    {
        std::cout << "Фильм уже уничтожен!\n";
    }
    std::cout << "\nДинамический массив объектов:\n";
    {
        std::unique_ptr<Film[]> filmArray = std::make_unique<Film[]>(2);
        filmArray[0].ChangeMinutes(100);
        filmArray[1].ChangeMinutes(120);
    }
    std::cout << "Массив уничтожен\n";
    std::cout << "\nМассив динамических объектов:\n";
    std::unique_ptr<Film> dynamicFilmArray[2];
    dynamicFilmArray[0] = std::make_unique<Film>("Дюна", 155, 12);
    dynamicFilmArray[1] = std::make_unique<Film>("Начало", 148, 12);
    dynamicFilmArray[0]->PrintInfo();
    dynamicFilmArray[1]->PrintInfo();
    return 0;
}