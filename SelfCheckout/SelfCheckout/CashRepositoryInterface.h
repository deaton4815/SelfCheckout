#pragma once

#include <iostream>

class CashRepositoryInterface
{
public:
	void emptyCashPurchasesDisplay(float) const;

private:
	void displayTwoDecimalFloat(float) const;
};

