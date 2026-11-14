using System;
class Program
{
    static void SellProduct(IStockItem item)
    {
        if (item.IsAvailable)
        {
            item.SellOne();
            Console.WriteLine("Продажа успешна!");
        }
    }
    static void TestSale(Popcorn popcorn)
    {
        try
        {
            popcorn.SellOne();
            Console.WriteLine("Продажа успешна!");
        }
        catch (OutOfStockException error)
        {
            Console.WriteLine(error.Message);
        }
        finally
        {
            Console.WriteLine("Проверка завершена");
        }
    }
    static void Main()
    {
        Popcorn popcorn = new Popcorn("Сырный", 400, 3);
        Drink drink = new Drink("Кола", 200, 2);
        SellProduct(popcorn);
        SellProduct(drink);
        BaseProduct product = popcorn;
        Console.WriteLine(product.GetName());
        Console.WriteLine(popcorn.GetName());
        Console.WriteLine(product.Describe());
        if (product is IStockItem stock)
            Console.WriteLine(stock.IsAvailable);
        BaseProduct combo = new Combo("Комбо", popcorn, drink, 10);
        IStockItem stockCombo = combo as IStockItem;
        Console.WriteLine(stockCombo == null);
        CashDesk cashDesk = new CashDesk(new StandardPricePolicy());
        Console.WriteLine(cashDesk.CalculatePrice(400));
        cashDesk.SetPolicy(new DiscountPricePolicy());
        Console.WriteLine(cashDesk.CalculatePrice(400));
        Popcorn[] goods = { new Popcorn("Сырный", 400), new Popcorn("Карамельный", 350)};
        Array.Sort(goods);
        foreach (Popcorn item in goods)
            Console.WriteLine(item.GetName());
        TestSale(new Popcorn("Пустой", 400, 0));
        TestSale(new Popcorn("Сладкий", 300, 1));
    }
}
