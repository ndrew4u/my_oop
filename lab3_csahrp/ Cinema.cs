using System;
namespace lab3_csahrp
{
    internal class Cinema
    {
        private string name;
        private Hall hall;
        public Cinema()
        {
            name = "";
            hall = new Hall();
            Console.WriteLine("Кинотеатр создан!\n");
        }
        public Cinema(string newName, int newNumber, int newSeats)
        {
            name = newName;
            hall = new Hall(newNumber, newSeats);
            Console.WriteLine("Кинотеатр создан!\n");
        }
        public void SetFilmToHall(Film newFilm)
        {
            hall.SetFilm(newFilm);
        }
        public void StartFilm()
        {
            hall.StartFilm();
        }
        public void StopFilm()
        {
            hall.StopFilm();
        }
        public void PrintInfo()
        {
            Console.WriteLine($"Название кинотеатра: {name}\n");
            hall.PrintInfo();
        }
        public override string ToString()
        {
            return $"Название кинотеатра: {name}\n" + hall.ToString();
        }
    }
}

