#pragma once
#include <iostream>
#include <concepts>
#include "IStockItem.hpp"
#include "BaseProduct.hpp"
template <typename T>
    requires std::derived_from<T, IStockItem>
class Stock
{
private:
    T& m_item;
public:
    Stock(T& item) 
        :m_item(item)
    {}
    bool IsAvailable() const
    {
        return m_item.IsAvailable();
    }
    void SellOne()
    {
        m_item.SellOne();
    }
    template <typename U>
        requires std::derived_from<U, IStockItem>
    void PrintTogether(const U& other) const
    {
        std::cout << m_item << "\n";
        std::cout << other << "\n";
    }
};