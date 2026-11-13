using System;
public class CashDesk
{
    private IPricePolicy m_policy;
    public CashDesk(IPricePolicy policy)
    {
        m_policy = policy;
    }
    public void SetPolicy(IPricePolicy policy)
    {
        m_policy = policy;
    }
    public int CalculatePrice(int price)
    {
        return m_policy.CalculatePrice(price);
    }
}