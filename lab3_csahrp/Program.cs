using System;
using static System.Console;
class Program
{
    static void Main()
    {
        var popcorn = new Popcorn("Сладкий", 250);
        var drink = new Drink("Кола", 150);
        var combo = new Combo("Комбо 1", popcorn, drink, 50);
        WriteLine("\n=== Полиморфизм ===");
        BaseProduct[] products =
        {
            new Popcorn("Солёный", 200),
            new Drink("Сок", 120),
            combo.Clone()
        };
        foreach (BaseProduct product in products)
        {
            WriteLine(product.Describe());
            WriteLine();
        }
        WriteLine("\n=== Копирование ===");
        Combo shallow = combo.ShallowCopy();
        Combo deep = combo.DeepCopy();
        popcorn.SetPrice(300);
        WriteLine("Оригинальное комбо: " + combo.GetPrice());
        WriteLine("Поверхностная копия: " + shallow.GetPrice());
        WriteLine("Глубокая копия: " + deep.GetPrice());
        WriteLine("\n=== Конструкторы ===");
        Popcorn ordinary = new Popcorn();
        Popcorn copied = new Popcorn(ordinary);
        WriteLine(copied.Describe());
        WriteLine("\n=== Сравнение объектов ===");
        Popcorn a = new Popcorn("Солёный", 200);
        Popcorn b = new Popcorn("Солёный", 200);
        WriteLine("Одинаковые по содержимому: " + a.Equals(b));
        WriteLine("Хеши равны: " + (a.GetHashCode() == b.GetHashCode()));
        WriteLine("\n=== Работа со строками ===");
        string name = combo.GetName();
        WriteLine("Поиск: " + name.Contains("Комбо"));
        WriteLine("Подстрока: " + name.Substring(0, "Комбо".Length));
        WriteLine("Сравнение: " + string.Compare(name, "Комбо 1"));
        WriteLine("\nВсего создано объектов: " + BaseProduct.GetCreatedCount());
    }
}
