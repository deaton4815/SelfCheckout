#pragma once

#include "BarcodeScanner.h"
#include "PayService.h"
#include "UserInterface.h"

class SelfCheckoutEngine
{
public:

	SelfCheckoutEngine();

private:

	BarcodeScanner m_scoScanner;
	PayService m_scoPayService;
	UserInterface m_scoUserInterface;

	void executeCustomerCheckout();
	void executeItemSelection();
	void executePayment();

	void scanItem(const int);
	void updatePrice();
	void displayCart();

	void executeCardPayment();
	void executeCashPayment();

	void emptyCashPurchases();
};