using System;
public abstract class BaseProduct
{
    protected string m_name;
    protected int m_price;
    private static int s_createdCount = 0;
    protected BaseProduct(string name, int price)
    {
        this.m_name = name;
        this.m_price = price;
        s_createdCount++;
        Console.WriteLine("Конструктор BaseProduct");
    }
    protected BaseProduct(BaseProduct other)
    {
        m_name = other.m_name;
        m_price = other.m_price;
        s_createdCount++;
        Console.WriteLine("Конструктор копирования BaseProduct");
    }
    public string GetName()
    {
        return m_name;
    }
    public void SetPrice(int price)
    {
        m_price = price;
    }
    public static int GetCreatedCount()
    {
        return s_createdCount;
    }
    public abstract int GetPrice();
    public virtual string Describe()
    {
        return "Название: " + m_name
            + "\nЦена: " + GetPrice();
    }
    public abstract BaseProduct Clone();
}
