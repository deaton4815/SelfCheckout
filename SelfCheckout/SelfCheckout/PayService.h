#pragma once

#include "CreditCardTerminal.h"

class PayService
{

public:

	void updatePrice(float);

	float getSubtotal();
	float getTax();
	float getTotal();

	int payElectronic();

	float getAmountDue();
	float getAmountPaid();
	
private:

	CreditCardTerminal m_scoCreditCardTerminal;

	float m_subtotal{ 0.f };
	float m_tax{ 0.f };
	const float m_taxRate{ 0.05f };
	float m_total{ 0.f };

	float m_amountDue{ 0.f };
	float m_amountPaid{ 0.f };

	float calculateTax();
	float calculateTotal();

	void setSubtotal(float);
	void setTax(float);
	void setTotal(float);
	void setAmountDue(float);
	void setAmountPaid(float);

};