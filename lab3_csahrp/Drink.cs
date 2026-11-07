using System;
public class Drink : BaseProduct
{
    public Drink(string name, int price)
        : base(name, price)
    {
        Console.WriteLine("Конструктор Drink");
    }
    public Drink(Drink other) : base(other)
    {
        Console.WriteLine("Конструктор копирования Drink");
    }
    public override int GetPrice()
    {
        return m_price;
    }
    public override string Describe()
    {
        return "Тип: Напиток\nНазвание: " + m_name
            + "\nЦена: " + m_price;
    }
    public override BaseProduct Clone()
    {
        return new Drink(this);
    }
}
