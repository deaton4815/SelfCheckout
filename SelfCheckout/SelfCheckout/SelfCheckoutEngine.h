/*
* Class is the main engine of the self checkout machine
*/
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
	static PayService m_scoPayService;
	UserInterface m_scoUserInterface;

	void executeSCO();
	
	int getPortalSelection();
	void executePortal(int);
	void executeCustomerPortal();
	void executeEmployeePortal();

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