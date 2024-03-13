/*
* Cash repository stores all cash deposited during purchases
*/
#pragma once
class CashRepository
{
public:
	void depositCash(float);
	float emptyRepository();

private:
	float m_repositoryAmount{ 0.f };

	void resetPurchaseRepository();

};

