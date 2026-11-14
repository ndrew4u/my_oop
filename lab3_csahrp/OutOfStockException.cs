using System;
public class OutOfStockException : Exception
{
    public OutOfStockException(string name)
        : base("Нет товара в наличии: " + name)
    {
    }
}
