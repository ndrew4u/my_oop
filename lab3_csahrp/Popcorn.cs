using System;
public sealed class Popcorn : BaseProduct, IStockItem, IComparable<Popcorn>
{
    private int m_count = 10;

    public Popcorn(string name, int price)
        : base(name, price)
    {
        Console.WriteLine("Конструктор Popcorn");
    }
    public Popcorn(string name, int price, int count)
        : this(name, price)
    {
        m_count = count;
    }
    public Popcorn() : this("Обычный", 100)
    {
        Console.WriteLine("Конструктор по умолчанию Popcorn");
    }
    public Popcorn(Popcorn other) : base(other)
    {
        m_count = other.m_count;
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
        return obj is Popcorn other && m_name == other.m_name && m_price == other.m_price;
    }
    public override int GetHashCode()
    {
        return HashCode.Combine(m_name, m_price);
    }
    public bool IsAvailable => m_count > 0;
    public void SellOne()
    {
        if (m_count <= 0)
        {
            throw new OutOfStockException(base.GetName());
        }
        --m_count;
    }
    public new string GetName()
    {
        return "Название: " + m_name;
    }
    public int CompareTo(Popcorn? other)
    {
        if (other is null) return 1;
        return string.Compare(m_name, other.m_name, StringComparison.CurrentCulture);
    }
}
