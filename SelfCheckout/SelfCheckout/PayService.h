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
	float getSubtotal();
	float getTax();
	float getTotal();
	float getAmountDue();
	float getAmountPaid();
	
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

	float calculateTax();
	float calculateTotal();

	void setSubtotal(float);
	void setTax(float);
	void setTotal(float);
	void setAmountDue(float);
	void setAmountPaid(float);

	void resetPayService();
};