using System;
using System.Collections.Generic;
using System.Text;

namespace lab3_csahrp
{
    internal class Film
    {
        private string name;
        private int minutes;
        private int ageLimit;
        public Film()
        {
            name = "";
            minutes = 0;
            ageLimit = 0;
            Console.WriteLine("Фильм создан!\n");
        }
        public Film(string newName, int newMinute, int newAgeLimit)
        {
            name = newName;
            if (newAgeLimit < 0) { Console.WriteLine("Ошибка! Возраст не может быть отрицательным!"); ageLimit = 0; }
            else { ageLimit = newAgeLimit; }
            if (newMinute <= 0) { Console.WriteLine("Ошибка! Длительность фильма не может быть отрицательной!\n"); minutes = 0; }
            else { minutes = newMinute; }
            Console.WriteLine("Фильм создан!\n");
        }
        public void ChangeMinute(int newMinute)
        {
            if (newMinute < 0) { Console.WriteLine("Ошибка! Длительность фильма не может быть отрицательной!\n"); }
            else { minutes = newMinute; Console.WriteLine("Длительность фильма изменена!\n"); }
        }
        public void ChangeName(string newName)
        {
            name = newName;
            Console.WriteLine("Название фильма изменено!\n");
        }
        public void ChangeAgelimit(int newAgeLimit)
        {
            if (newAgeLimit < 0) { Console.WriteLine("Ошибка! Возраст не может быть отрицательным!"); }
            else { ageLimit = newAgeLimit; Console.WriteLine("Возрастной лимит изменен!\n"); }
        }
        public void PrintInfo()
        {
            Console.WriteLine($"Название фильма: {name}\n");
            Console.WriteLine($"Длительность фильма: {minutes}\n");
            Console.WriteLine($"Возрастное ограничение: {ageLimit}+\n");
        }
        public void CheckAge(int newAge)
        {
            if (newAge < ageLimit) { Console.WriteLine("Просмотр фильма запрещен!\n"); }
            else { Console.WriteLine("Просмтр фильма разрешен!\n"); }

        }
        public override string ToString()
        {
            return $"Название фильма: {name}\n Продолжительность: {minutes} мин.\n Возрастное ограничение: {ageLimit}+\n";
        }
        public string Name
        {
            get { return name; }
        }
        public int Minutes
        {
            get { return minutes; }
        }
        public int AgeLimit
        { 
            get { return ageLimit; } 
        }
    }
}
