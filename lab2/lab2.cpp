#include "Popcorn.hpp"
#include "Drink.hpp"
#include "Combo.hpp"
#include <iostream>
#include <memory>
#include<locale.h>
int main()
{
    setlocale(LC_ALL, "RUS");
    auto popcorn = std::make_shared<Popcorn>("Сладкий", 250);
    auto drink = std::make_shared<Drink>("Кола", 150);
    Combo combo("Комбо 1", popcorn, drink, 50);
    std::cout << combo.Describe() << '\n';
    std::unique_ptr<BaseProduct> products[3];
    products[0] = std::make_unique<Popcorn>("Солёный", 200);
    products[1] = std::make_unique<Drink>("Сок", 120);
    products[2] = combo.Clone();
    for (int i = 0; i < 3; i++)
    {
        std::cout << products[i]->Describe() << "\n\n";
    }
    std::cout << "\n=== Проверка копирования ===\n";
    auto shallow = popcorn;
    Combo deep = combo;
    popcorn->SetPrice(300);
    std::cout << "Оригинальный попкорн: " << popcorn->GetPrice() << '\n';
    std::cout << "Поверхностная копия: " << shallow->GetPrice() << '\n';
    std::cout << "Оригинальное комбо: " << combo.GetPrice() << '\n';
    std::cout << "Глубокая копия комбо: " << deep.GetPrice() << '\n';
    std::cout << "\n=== Проверка присваивания ===\n";
    Combo second("Второй набор", popcorn, drink, 20);
    second = combo;
    std::cout << second.Describe() << '\n';
    second = second;
    std::cout << "Самоприсваивание прошло\n";
    std::cout << "\n=== Проверка конструкторов ===\n";
    Popcorn ordinary;
    Popcorn original("Карамельный", 180);
    Popcorn copied(original);
    Popcorn moved(std::move(original));
    std::cout << copied.Describe() << '\n';
    std::cout << moved.Describe() << '\n';
    std::cout << "\n=== Проверка строк ===\n";
    std::string name = combo.GetName();
    std::cout << "Поиск: " << (name.find("Комбо") != std::string::npos) << '\n';
    std::cout << "Подстрока: " << name.substr(0, 5) << '\n';
    std::cout << "Сравнение: " << name.compare("Комбо 1") << '\n';
    std::cout << "\n=== Проверка деструктора ===\n";
    std::unique_ptr<BaseProduct> test = std::make_unique<Popcorn>("Тестовый", 100);
    test.reset();
    return 0;
}