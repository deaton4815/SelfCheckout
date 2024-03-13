/*
* Class is the engine for pricing and payments
* Calculates grocery bill and executes payments through
* the credit card terminal or cash and change repositories
*/
#pragma once

#include "CreditCardTerminal.h"
#include "CashRepository.h"
#include "ChangeRepository.h"

class PayService
{
public:

	int payElectronic();

	bool payCash(float);
	float getChange();
	float emptyCashPurchases();

	void updatePrice(float);
	float getSubtotal() const;
	float getTax() const;
	float getTotal() const;
	float getAmountDue() const;
	float getAmountPaid() const;

	void resetPayService();
	
private:

	CreditCardTerminal m_scoCreditCardTerminal;
	CashRepository m_scoCashPurchase;
	ChangeRepository m_scoChange;

	float m_subtotal{ 0.f };
	float m_tax{ 0.f };
	const float m_taxRate{ 0.05f };
	float m_total{ 0.f };

	float m_amountDue{ 0.f };
	float m_amountPaid{ 0.f };

	void addCashPurchase(float);

	float calculateTax() const;
	float calculateTotal() const;

	void setSubtotal(float);
	void setTax(float);
	void setTotal(float);
	void setAmountDue(float);
	void setAmountPaid(float);
};