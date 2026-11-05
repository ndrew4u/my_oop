#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <locale.h>
#include "BaseProduct.hpp"
#include "Popcorn.hpp"
#include "Drink.hpp"
#include "Combo.hpp"
int main()
{
    setlocale(LC_ALL, "RUS");
    Popcorn p1;
    Popcorn p2("Сладкий", 250);
    Popcorn p3 = p2;
    Popcorn p4 = std::move(p3);
    auto popcorn = std::make_shared<Popcorn>("Сладкий", 250);
    auto drink = std::make_shared<Drink>("Кола", 150);
    Combo combo1(popcorn, drink, 50);
    auto combo2 = combo1.ShallowCopy();
    Combo combo3 = combo1;
    popcorn->SetPrice(300);
    std::cout << "Исходное комбо: "
        << combo1.GetPrice() << "\n";
    std::cout << "Поверхностная копия: "
        << combo2->GetPrice() << "\n";
    std::cout << "Глубокая копия: "
        << combo3.GetPrice() << "\n";
    combo1 = combo1;
    combo1.CopyTo(combo3);
    std::unique_ptr<BaseProduct> products[2];
    products[0] = std::make_unique<Popcorn>("Сладкий", 250);
    products[1] = std::make_unique<Drink>("Кола", 150);
    for (int i = 0; i < 2; i++)
    {
        std::cout << products[i]->Describe() << "\n";
    }
    std::string name = "Popcorn";
    std::cout << name.find("corn") << "\n";
    std::cout << name.substr(3, 4) << "\n";
    std::cout << name + " сладкий\n";
    std::cout << (name == "Popcorn") << "\n";
    std::cout << "Всего создано товаров: " << BaseProduct::GetCreatedCount() << "\n";
    return 0;
}
