public class StandardPricePolicy : IPricePolicy
{
    public int CalculatePrice(int price)
    {
        return price;
    }
}