#include"IPricePolicy.hpp"
#include<memory>
class CashDesk
{
private:
	std::unique_ptr<IPricePolicy> m_policy;
public:
	int CalculatePrice(int price) const;
	CashDesk(std::unique_ptr<IPricePolicy> policy);
	void SetPolicy(std::unique_ptr<IPricePolicy> policy);
};