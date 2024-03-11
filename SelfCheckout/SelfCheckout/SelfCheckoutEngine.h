#pragma once

#include "BarcodeScanner.h"
#include "PayService.h"
#include "UserInterface.h"

class SelfCheckoutEngine
{
public:

	SelfCheckoutEngine();

private:
	//unsigned int getUserSelection();
	//void executeUserSelection();
	BarcodeScanner m_scoScanner;
	PayService m_scoPayService;
	UserInterface m_scoUserInterface;

	void executeCustomerCheckout();
	void executeItemSelection();
	void scanItem(const int);
	void updatePrice();
	void displayCart();
};