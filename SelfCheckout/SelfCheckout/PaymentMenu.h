#pragma once
#include "SelectionMenu.h"

#include <iostream>

class PaymentMenu : public SelectionMenu
{
private:

	void displayMenuHeader() const override;
	void displayMenuOptions() const override;
};