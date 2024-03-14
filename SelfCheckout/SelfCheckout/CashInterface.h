#pragma once

#include <iostream>
#include <iomanip>

class CashInterface
{

public:

	float getCash() const;
	float getCash(float) const;

	void displayChange(float) const;

private:

	void displayCashPaymentPrompt() const;
	void displayCashPaymentPrompt(float) const;

	void displayTwoDecimalFloat(float) const;
};