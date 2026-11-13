using System;
public class Drink : BaseProduct, IStockItem
{
    private int m_count = 10;

    public Drink(string name, int price)
        : base(name, price)
    {
        Console.WriteLine("Конструктор Drink");
    }
    public Drink(string name, int price, int count)
        : this(name, price)
    {
        m_count = count;
    }
    public Drink(Drink other) : base(other)
    {
        m_count = other.m_count;
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
    public bool IsAvailable => m_count > 0;
    public void SellOne()
    {
        if (m_count <= 0)
        {
            throw new OutOfStockException(GetName());
        }
        --m_count;
    }
}