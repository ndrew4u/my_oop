using System;
using System.Numerics;
class Program
{
    static T CalculateTotalPrice<T>(T firstPrice, T secondPrice) where T : INumber<T>
    {
        return firstPrice + secondPrice;
    }
    static void Main()
    {
        CashDesk cashDesk = new CashDesk(new StandardPricePolicy());
        Console.WriteLine(cashDesk.CalculatePrice(100));
        Console.WriteLine(cashDesk.CalculatePrice(100, 2));
        cashDesk.SetPolicy(new DiscountPricePolicy());
        Console.WriteLine(cashDesk.CalculatePrice(100));
        Console.WriteLine(cashDesk.CalculatePrice(100, 2));
        Popcorn p1 = new Popcorn("Сырный", 150, 5);
        Popcorn p2 = new Popcorn("Сырный", 150, 3);
        Console.WriteLine(p1 == p2);
        Console.WriteLine(p1 != p2);
        Popcorn p3 = p1 + p2;
        Console.WriteLine(p3.StockCount);
        p1 += p2;
        Console.WriteLine(p1.StockCount);
        Console.WriteLine(((BaseProduct)p1).ToString());
        Console.WriteLine(CalculateTotalPrice(150, 100));
        Console.WriteLine(CalculateTotalPrice(150.5, 100.75));
        Drink d1 = new Drink("Вода", 100, 10);
        Stock<Popcorn> popcornStock = new Stock<Popcorn>(p1);
        Stock<Drink> drinkStock = new Stock<Drink>(d1);
        Console.WriteLine(popcornStock.IsAvailable());
        popcornStock.SellOne();
        popcornStock.PrintTogether(d1);
        drinkStock.SellOne();
        drinkStock.PrintTogether(p1);
    }
}
