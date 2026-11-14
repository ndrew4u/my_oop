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
    Popcorn popcorn1("Сырный", 400, 5);
    Drink drink1("Кола", 200, 5);
    SellProduct(popcorn1);
    SellProduct(drink1);
    BaseProduct& item = popcorn1;
    std::cout << "Через BaseProduct: " << item.GetName() << "\n";
    std::cout << "Через Popcorn: " << popcorn1.GetName() << "\n";
    std::cout << item.Describe() << "\n";
    TrySell(popcorn1);
    auto comboPopcorn =std::make_shared<Popcorn>("Карамельный", 350, 5);
    auto comboDrink = std::make_shared<Drink>("Сок", 150, 5);
    Combo combo("Комбо-набор", comboPopcorn, comboDrink, 10);
    TrySell(combo);
    CashDesk cashDesk(std::make_unique<StandardPricePolicy>());
    std::cout << "Обычная цена: " << cashDesk.CalculatePrice(400) << "\n";
    cashDesk.SetPolicy(std::make_unique<DiscountPricePolicy>());
    std::cout << "Цена со скидкой: " << cashDesk.CalculatePrice(400) << "\n";
    Popcorn popcornEmpty("Пустой", 400, 0);
    Popcorn popcornAvailable("Сладкий", 300, 5);
    try
    {
        popcornEmpty.SellOne();
        std::cout << "Продажа успешна!\n";
    }
    catch (const OutOfStockError& error)
    {
        std::cout << error.what() << "\n";
    }
    catch (const std::exception& error)
    {
        std::cout << "Ошибка: " << error.what() << "\n";
    }
    try
    {
        popcornAvailable.SellOne();
        std::cout << "Продажа успешна!\n";
    }
    catch (const OutOfStockError& error)
    {
        std::cout << error.what() << "\n";
    }
    catch (const std::exception& error)
    {
        std::cout << "Ошибка: " << error.what() << "\n";
    }
    return 0;
}