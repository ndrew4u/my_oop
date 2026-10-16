using System;
namespace lab3_csahrp
{
    internal class Film
    {
        private string _name;
        private int _minutes;
        private int _ageLimit;
        public Film()
        {
            _name = "";
            _minutes = 0;
            _ageLimit = 0;
            Console.WriteLine("Фильм создан!\n");
        }
        public Film(string newName, int newMinute, int newAgeLimit)
        {
            _name = newName;

            if (newAgeLimit < 0)
            {
                Console.WriteLine("Ошибка! Возраст не может быть отрицательным!");
                _ageLimit = 0;
            }
            else
            {
                _ageLimit = newAgeLimit;
            }

            if (newMinute <= 0)
            {
                Console.WriteLine("Ошибка! Длительность фильма должна быть больше 0!\n");
                _minutes = 0;
            }
            else
            {
                _minutes = newMinute;
            }

            Console.WriteLine("Фильм создан!\n");
        }
        public void ChangeMinute(int newMinute)
        {
            if (newMinute <= 0)
            {
                Console.WriteLine("Ошибка! Длительность фильма должна быть больше 0!\n");
            }
            else
            {
                _minutes = newMinute;
                Console.WriteLine("Длительность фильма изменена!\n");
            }
        }
        public void ChangeName(string newName)
        {
            _name = newName;
            Console.WriteLine("Название фильма изменено!\n");
        }
        public void ChangeAgelimit(int newAgeLimit)
        {
            if (newAgeLimit < 0)
            {
                Console.WriteLine("Ошибка! Возраст не может быть отрицательным!");
            }
            else
            {
                _ageLimit = newAgeLimit;
                Console.WriteLine("Возрастной лимит изменен!\n");
            }
        }
        public void PrintInfo()
        {
            Console.WriteLine($"Название фильма: {_name}\n");
            Console.WriteLine($"Длительность фильма: {_minutes}\n");
            Console.WriteLine($"Возрастное ограничение: {_ageLimit}+\n");
        }
        public void CheckAge(int newAge)
        {
            if (newAge < _ageLimit)
            {
                Console.WriteLine("Просмотр фильма запрещен!\n");
            }
            else
            {
                Console.WriteLine("Просмотр фильма разрешен!\n");
            }
        }
        public override string ToString()
        {
            return $"Название фильма: {_name}\n Продолжительность: {_minutes} мин.\n Возрастное ограничение: {_ageLimit}+\n";
        }
        public string Name
        {
            get { return _name; }
        }
        public int Minutes
        {
            get { return _minutes; }
        }
        public int AgeLimit
        {
            get { return _ageLimit; }
        }
    }
}