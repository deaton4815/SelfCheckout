/*
* Class executes IO involving prices, payments, and receipts
*/
#pragma once

#include "PaymentMenu.h"
#include "CartIO.h"
#include "CardIO.h"
#include "CashIO.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PaymentIO
{

public:

	int getPaymentSelection(const float, const float, const float);

	void displayCart(const vector<unsigned int>&, const vector<string>&,
		const vector<string>&, const vector<float>&) const;

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
	CartIO m_cart;
	const CardIO m_card;
	const CashIO m_cash;

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

