#pragma once

#include <iostream>
#include <iomanip>

class CashRepositoryIO
{
public:
	void emptyCashPurchasesDisplay(const float) const;

private:
	void displayTwoDecimalFloat(const float) const;
};