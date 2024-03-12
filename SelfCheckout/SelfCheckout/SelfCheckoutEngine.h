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

	void executeSCO();
	
	int getPortalSelection();
	void executePortalSelection(int);
	void executeCustomerSelection();
	void executeEmployeeSelection();

	void executeItemSelection();
	void executeItemRemoval();
	void executePayment();

	void displayCart();
	void displayFullPrice();

	void executeCardPayment();
	void executeCashPayment();

	void printCardReceipt(int);
	void printCashReceipt(float);


	void emptyCashPurchases();
};