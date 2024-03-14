/*
* Class is the main engine of the self checkout machine
*/
#pragma once

#include "BarcodeScanner.h"
#include "PayService.h"
#include "UserInterface.h"

class SelfCheckoutMachine
{
public:
	
	SelfCheckoutMachine();

private:

	UserInterface m_scoUserInterface;
	BarcodeScanner m_scoScanner;
	PayService m_scoPayService;

	void executeSCO();
	int getPortalSelection();
	void executePortal(int);

	void executeCustomerPortal();
	void scanItem();
	void removeItem();
	void pay();
	void displayCart();
	int getPaymentType();
	void printReceipt(int);
	void printReceipt(float);
	void payCard();
	void payCash();

	void executeEmployeePortal();
	void emptyCashPurchases();
};