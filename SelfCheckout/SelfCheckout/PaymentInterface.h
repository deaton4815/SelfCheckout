#pragma once

#include "PaymentMenu.h"
#include "CartInterface.h"
#include "CardInterface.h"
#include "CashInterface.h"

class PaymentInterface
{

public:

	void printReceipt(vector<unsigned int>, vector<string>,
		vector<string>, vector<float>,
		float, float, float) const;
	void printReceipt(vector<unsigned int>, vector<string>,
		vector<string>, vector<float>,
		float, float, int) const;

	void displaySubtotal(float);

private:

	PaymentMenu m_menuInterface;
	CartInterface m_cart;

	int getPaymentSelection();

	void printReceiptHeader();

	void displayTwoDecimalFloat(float);
};

