using System;
namespace lab3_csahrp
{
    internal class Cinema
    {
        private string _name;
        private Hall _hall;
        public Cinema()
        {
            _name = "";
            _hall = new Hall();
            Console.WriteLine("Кинотеатр создан!\n");
        }
        public Cinema(string newName, int newNumber, int newSeats)
        {
            _name = newName;
            _hall = new Hall(newNumber, newSeats);
            Console.WriteLine("Кинотеатр создан!\n");
        }
        public void SetFilmToHall(Film newFilm)
        {
            _hall.SetFilm(newFilm);
        }
        public void StartFilm()
        {
            _hall.StartFilm();
        }
        public void StopFilm()
        {
            _hall.StopFilm();
        }
        public void PrintInfo()
        {
            Console.WriteLine($"Название кинотеатра: {_name}\n");
            _hall.PrintInfo();
        }
        public override string ToString()
        {
            return $"Название кинотеатра: {_name}\n" + _hall.ToString();
        }
    }
}

