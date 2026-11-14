#include "CashDesk.hpp"
int CashDesk::CalculatePrice(int price) const
{
	return m_policy->CalculatePrice(price);
}
CashDesk::CashDesk(std::unique_ptr<IPricePolicy> policy)
	: m_policy{std::move(policy)}
{
}
void CashDesk::SetPolicy(std::unique_ptr<IPricePolicy> policy)
{
	m_policy = std::move(policy);
}