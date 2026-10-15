using System;
namespace lab3_csahrp
{
    internal class Hall
    {
        private int number;
        private int seats;
        private Film? film;
        private bool isFilmStarted;
        public Hall()
        {
            number = 0;
            seats = 0;
            film = null;
            isFilmStarted = false;
            Console.WriteLine("Зал создан!\n");
        }
        public Hall(int newNumber, int newSeats)
        {
            if (newNumber <= 0)
            {
                Console.WriteLine("Ошибка! Номер зала должен быть больше нуля!\n");
                number = 0;
            }
            else
            {
                number = newNumber;
            }

            if (newSeats <= 0)
            {
                Console.WriteLine("Ошибка! Количество мест должно быть больше нуля!\n");
                seats = 0;
            }
            else
            {
                seats = newSeats;
            }
            film = null;
            isFilmStarted = false;
            Console.WriteLine("Зал создан!\n");
        }
        public void SetFilm(Film newfilm)
        {
            if (isFilmStarted == true) { Console.WriteLine("Ошибка! Нельзя изменить фильм во время показа!\n"); }
            else { film = newfilm; Console.WriteLine("Фильм назначен в зал!\n"); }
        }
        public void StartFilm()
        {
            if (film == null)
            {
                Console.WriteLine("Ошибка! Фильм не назначен!\n");
            }
            else if (isFilmStarted == true)
            {
                Console.WriteLine("Ошибка! Фильм уже идёт!\n");
            }
            else
            {
                isFilmStarted = true;
                Console.WriteLine("Фильм запущен!\n");
            }
        }
        public void StopFilm()
        {
            if (isFilmStarted == false) { Console.WriteLine("Ошибка! Фильм уже остановлен!\n"); }
            else { isFilmStarted = false; Console.WriteLine("Фильм остановлен!\n"); }
        }
        public void PrintInfo()
        {
            Console.WriteLine($"Номер зала: {number}\n");
            Console.WriteLine($"Кол-во мест: {seats}\n");
            if (film != null) { Console.WriteLine($"Фильм: {film.Name}\n"); }
            else { Console.WriteLine("Фильм не назначен!\n"); }
            Console.WriteLine("Состояние показа: ");
            if (isFilmStarted == true) { Console.WriteLine("Идет\n"); }
            else { Console.WriteLine("Не идет\n"); }
        }
        public override string ToString()
        {
            string filmName;
            if (film == null)
            {
                filmName = "Не назначен";
            }
            else
            {
                filmName = film.Name;
            }
            string status;
            if (isFilmStarted)
            {
                status = "Идёт";
            }
            else
            {
                status = "Не идёт";
            }
            return $"Номер зала: {number}\n Количество мест: {seats}\n Фильм: {filmName}\n Состояние показа: {status}";
        }
    }
}
