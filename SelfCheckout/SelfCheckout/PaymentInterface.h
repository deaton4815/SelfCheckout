/*
* Class executes IO involving prices, payments, and receipts
*/
#pragma once

#include "PaymentMenu.h"
#include "CartInterface.h"
#include "CardInterface.h"
#include "CashInterface.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PaymentInterface
{

public:

	int getPaymentSelection(const float, const float, const float);

	void printReceipt(const vector<unsigned int>&, const vector<string>&,
		const vector<string>&, const vector<float>&,
		const float, const float, const float,
		const float, const float, const int) const;

	void printReceipt(const vector<unsigned int>&, const vector<string>&,
		const vector<string>&, const vector<float>&,
		const float, const float, const float,
		const float, const float, const float) const;

	void displayFullPrice(const float, const float, const float) const;
	void displaySubtotal(float) const;

	float getCash() const;
	float getCash(float) const;

private:

	PaymentMenu m_paymentType;
	CartInterface m_cart;
	const CardInterface m_card;
	const CashInterface m_cash;

	void printReceiptHeader() const;

	void displayPayment(const float, const float, const int) const;
	void displayPayment(const float, const float, const float) const;

	void displayTax(const float) const;
	void displayTotal(const float) const;
	void displayDue(const float) const;
	void displayPaid(const float) const;
	void displayCode(const int) const;
	void displayChange(const float) const;

	void displayValue(const string&, const float) const;
	void displayValue(const string&, const int) const;

	void displayTwoDecimalFloat(const float) const;
};

