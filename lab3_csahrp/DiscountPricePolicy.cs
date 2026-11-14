public class DiscountPricePolicy : IPricePolicy
{
    public int CalculatePrice(int price)
    {
        return (int)(price - price * 0.1);
    }
}