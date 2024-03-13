#pragma once

#include "PaymentMenu.h"

class PaymentInterface
{

public:

	void executePayment();

private:

	PaymentMenu m_menuInterface;

	int getPaymentSelection();
};

