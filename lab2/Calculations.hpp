#pragma once
template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;
template <Numeric T>
T CalculateTotalPrice(T firstprice, T secondprice)
{
	return firstprice + secondprice;
}