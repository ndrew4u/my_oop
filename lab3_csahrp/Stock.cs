using System;
public class Stock<T> where T : IStockItem
{
    private T m_item;
    public Stock(T item)
    {
        m_item = item;
    }
    public bool IsAvailable()
    {
        return m_item.IsAvailable;
    }
    public void SellOne()
    {
        m_item.SellOne();
    }
    public void PrintTogether<U>(U other) where U : IStockItem
    {
        Console.WriteLine(m_item);
        Console.WriteLine(other);
    }
}