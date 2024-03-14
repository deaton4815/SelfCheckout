/*
* Class handles cash prompting, acceptance, and dispensing to the customer
*/
#pragma once

#include <iostream>
#include <iomanip>

class CashInterface
{

public:

	float getCash() const;
	float getCash(const float) const;

	void displayChange(const float) const;

private:

	void displayCashPaymentPrompt() const;
	void displayCashPaymentPrompt(const float) const;

	void displayTwoDecimalFloat(const float) const;
};