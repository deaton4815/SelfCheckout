#pragma once

#include "PaymentMenu.h"
#include "CartInterface.h"
#include "CardInterface.h"
#include "CashInterface.h"

#include <iostream>
#include <string>

using namespace std;

class PaymentInterface
{

public:

	int getPaymentSelection(float, float, float);

	void printReceipt(vector<unsigned int>, vector<string>,
		vector<string>, vector<float>,
		float, float, float,
		float, float, int) const;

	void printReceipt(vector<unsigned int>, vector<string>,
		vector<string>, vector<float>,
		float, float, float,
		float, float, float) const;

	void displaySubtotal(float) const;

private:

	PaymentMenu m_paymentType;
	CartInterface m_cart;

	void printReceiptHeader() const;

	void displayFullPrice(float, float, float) const;
	void displayPayment(float, float, int) const;
	void displayPayment(float, float, float) const;

	void displayTax(float) const;
	void displayTotal(float) const;
	void displayDue(float) const;
	void displayPaid(float) const;
	void displayCode(int) const;
	void displayChange(float) const;

	void displayValue(const string&, float) const;
	void displayValue(const string&, int) const;

	void displayTwoDecimalFloat(float) const;
};

