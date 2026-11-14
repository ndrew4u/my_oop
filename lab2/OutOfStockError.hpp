#pragma once
#include <stdexcept>
class OutOfStockError : public std::runtime_error
{
public:
    explicit OutOfStockError(std::string_view name)
        : std::runtime_error{"Нет товара в наличии: " + std::string(name)}
    {
    }
};