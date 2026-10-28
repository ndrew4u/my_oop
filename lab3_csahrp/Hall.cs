using System;
namespace lab3_csahrp
{
    internal class Hall
    {
        private int _number;
        private int _seats;
        private Film? _film;
        private bool _isFilmStarted;
        public Hall()
        {
            _number = 0;
            _seats = 0;
            _film = null;
            _isFilmStarted = false;
            Console.WriteLine("Зал создан!\n");
        }
        public Hall(int newNumber, int newSeats)
        {
            if (newNumber <= 0)
            {
                Console.WriteLine("Ошибка! Номер зала должен быть больше нуля!\n");
                _number = 0;
            }
            else
            {
                _number = newNumber;
            }
            if (newSeats <= 0)
            {
                Console.WriteLine("Ошибка! Количество мест должно быть больше нуля!\n");
                _seats = 0;
            }
            else
            {
                _seats = newSeats;
            }
            _film = null;
            _isFilmStarted = false;
            Console.WriteLine("Зал создан!\n");
        }
        public void SetFilm(Film newFilm)
        {
            if (_isFilmStarted == true)
            {
                Console.WriteLine("Ошибка! Нельзя изменить фильм во время показа!\n");
            }
            else
            {
                _film = newFilm;
                Console.WriteLine("Фильм назначен в зал!\n");
            }
        }
        public void StartFilm()
        {
            if (_film == null)
            {
                Console.WriteLine("Ошибка! Фильм не назначен!\n");
            }
            else if (_isFilmStarted == true)
            {
                Console.WriteLine("Ошибка! Фильм уже идёт!\n");
            }
            else
            {
                _isFilmStarted = true;
                Console.WriteLine("Фильм запущен!\n");
            }
        }
        public void StopFilm()
        {
            if (_isFilmStarted == false)
            {
                Console.WriteLine("Ошибка! Фильм уже остановлен!\n");
            }
            else
            {
                _isFilmStarted = false;
                Console.WriteLine("Фильм остановлен!\n");
            }
        }
        public void PrintInfo()
        {
            Console.WriteLine($"Номер зала: {_number}\n");
            Console.WriteLine($"Кол-во мест: {_seats}\n");
            if (_film != null)
            {
                Console.WriteLine($"Фильм: {_film.Name}\n");
            }
            else
            {
                Console.WriteLine("Фильм не назначен!\n");
            }
            Console.WriteLine("Состояние показа: ");
            if (_isFilmStarted == true)
            {
                Console.WriteLine("Идет\n");
            }
            else
            {
                Console.WriteLine("Не идет\n");
            }
        }
        public override string ToString()
        {
            string filmName;
            if (_film == null)
            {
                filmName = "Не назначен";
            }
            else
            {
                filmName = _film.Name;
            }
            string status;
            if (_isFilmStarted)
            {
                status = "Идёт";
            }
            else
            {
                status = "Не идёт";
            }
            return $"Номер зала: {_number}\n Количество мест: {_seats}\n Фильм: {filmName}\n Состояние показа: {status}";
        }
    }
}