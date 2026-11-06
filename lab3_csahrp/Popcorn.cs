using System;
public sealed class Popcorn : BaseProduct
{
    public Popcorn(string name, int price)
        : base(name, price)
    {
        Console.WriteLine("Конструктор Popcorn");
    }
    public Popcorn() : this("Обычный", 100)
    {
        Console.WriteLine("Конструктор по умолчанию Popcorn");
    }
    public Popcorn(Popcorn other) : base(other)
    {
        Console.WriteLine("Конструктор копирования Popcorn");
    }
    public override int GetPrice()
    {
        return m_price;
    }
    public override string Describe()
    {
        return "Тип: Попкорн\n" + base.Describe();
    }
    public override BaseProduct Clone()
    {
        return new Popcorn(this);
    }
    public override bool Equals(object? obj)
    {
        return obj is Popcorn other
            && m_name == other.m_name
            && m_price == other.m_price;
    }
    public override int GetHashCode()
    {
        return HashCode.Combine(m_name, m_price);
    }
}
