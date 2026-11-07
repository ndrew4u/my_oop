using System;
public class Combo : BaseProduct
{
    private BaseProduct m_popcorn;
    private BaseProduct m_drink;
    private int m_discount;
    public Combo(string name, BaseProduct popcorn,
                 BaseProduct drink, int discount)
        : base(name, 0)
    {
        m_popcorn = popcorn;
        m_drink = drink;
        m_discount = discount;

        Console.WriteLine("Конструктор Combo");
    }
    public Combo(Combo other) : base(other)
    {
        m_popcorn = other.m_popcorn.Clone();
        m_drink = other.m_drink.Clone();
        m_discount = other.m_discount;

        Console.WriteLine("Конструктор копирования Combo");
    }
    public Combo ShallowCopy()
    {
        return (Combo)MemberwiseClone();
    }
    public Combo DeepCopy()
    {
        var copy = (Combo)MemberwiseClone();
        copy.m_popcorn = m_popcorn.Clone();
        copy.m_drink = m_drink.Clone();
        return copy;
    }
    public override BaseProduct Clone()
    {
        return DeepCopy();
    }
    public override int GetPrice()
    {
        return m_popcorn.GetPrice()+ m_drink.GetPrice() - m_discount;
    }
    public override string Describe()
    {
        return "Тип: Комбо\nНазвание: " + m_name
            + "\n\nПопкорн:\n" + m_popcorn.Describe()
            + "\n\nНапиток:\n" + m_drink.Describe()
            + "\n\nСкидка: " + m_discount
            + "\nИтоговая цена: " + GetPrice();
    }
}
