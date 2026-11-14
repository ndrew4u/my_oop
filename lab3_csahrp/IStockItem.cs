public interface IStockItem
{
    bool IsAvailable { get; }
    void SellOne();
}
