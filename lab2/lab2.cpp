#include <iostream>
#include <memory>
#include <clocale>
#include <exception>
#include "BaseProduct.hpp"
#include "Popcorn.hpp"
#include "Drink.hpp"
#include "Combo.hpp"
#include "IStockItem.hpp"
#include "IPricePolicy.hpp"
#include "StandardPricePolicy.hpp"
#include "DiscountPricePolicy.hpp"
#include "CashDesk.hpp"
#include "OutOfStockError.hpp"
#include "Calculations.hpp"
#include "Stock.hpp"
void SellProduct(IStockItem& item)
{
    if (item.IsAvailable())
    {
        item.SellOne();
        std::cout << "Успешная продажа!\n";
    }
    else
    {
        std::cout << "Товара нет!\n";
    }
}
void TrySell(BaseProduct& item)
{
    if (auto* stock = dynamic_cast<IStockItem*>(&item))
    {
        std::cout << "Товар поддерживает IStockItem\n";
        stock->SellOne();
    }
    else
    {
        std::cout << item.GetName()
            << ": интерфейс IStockItem не поддерживается\n";
    }
}
int main()
{
    setlocale(LC_ALL, "RUS");
    std::cout << std::boolalpha;
    Popcorn p1("Сырный", 150, 5);
    Popcorn p2("Сырный", 150, 3);
    Drink d1("Вода", 100, 10);
    std::cout << "=== 1. Перегрузка методов ===\n";
    CashDesk cashDesk(std::make_unique<StandardPricePolicy>());
    std::cout << cashDesk.CalculatePrice(100) << "\n";
    std::cout << cashDesk.CalculatePrice(100, 2) << "\n";
    cashDesk.SetPolicy(std::make_unique<DiscountPricePolicy>());
    std::cout << cashDesk.CalculatePrice(100) << "\n";
    std::cout << cashDesk.CalculatePrice(100, 2) << "\n";
    std::cout << "\n=== 2. Перегрузка операторов ===\n";
    std::cout << "== : " << (p1 == p2) << "\n";
    std::cout << "< : " << (p1 < p2) << "\n";
    Popcorn p3 = p1 + p2;
    std::cout << "+ : " << p3 << "\n";
    std::cout << "p1 после + : " << p1 << "\n";
    p1 += p2;
    std::cout << "+= : " << p1 << "\n";
    std::cout << "\n=== 3. Дружественные функции ===\n";
    std::cout << p1 << "\n";
    BaseProduct& product1 = p1;
    BaseProduct& product2 = d1;
    std::cout << product1 << "\n";
    std::cout << product2 << "\n";
    std::cout << "\n=== 4. Шаблонная функция ===\n";
    std::cout << CalculateTotalPrice(p1.GetPrice(), d1.GetPrice()) << "\n";
    std::cout << CalculateTotalPrice(150.5, 100.75) << "\n";
    std::cout << "\n=== 5. Шаблонный класс ===\n";
    Stock<Popcorn> popcornStock(p1);
    Stock<Drink> drinkStock(d1);
    std::cout << popcornStock.IsAvailable() << "\n";
    popcornStock.SellOne();
    popcornStock.PrintTogether(d1);
    std::cout << drinkStock.IsAvailable() << "\n";
    drinkStock.SellOne();
    drinkStock.PrintTogether(p1);
    return 0;
}