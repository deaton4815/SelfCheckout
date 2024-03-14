#pragma once

#include <iostream>
#include <iomanip>

class CashRepositoryInterface
{
public:
	void emptyCashPurchasesDisplay(const float) const;

private:
	void displayTwoDecimalFloat(const float) const;
};

