#pragma once

#include "PortalMenu.h"

using namespace std;

class UserInterface
{
public:

	int getPortalSelection();

private:
	PortalMenu m_portal;
}


/*
public:

	int getPortalSelection();

	int getCustomerSelection();
	int getItemSelection();
	int getPaymentOption();

	int getEmployeeSelection();

	float getCash(bool);

	void displayReceiptHeader();
	void displayReceiptFooter();

	void displayCart(vector<unsigned int>, vector<string>,
		vector<string>, vector<float>, float);

	void displayFullPrice(float, float, float);

	void displayCardPayment(int, float, float);
	void displayCashPayment(float, float, float);

	void emptyCashPurchasesDisplay(float);

private:

	void displayOpeningMessage();
	void displayPortalPrompts();

	void displayCustomerPrompt();

	void displayEmployeePrompt();
	
	void displayAvailableItems();

	void displayItem(unsigned int, string, string, float);

	void displayCartHeader();
	void displayItemNumber(unsigned int);
	void displayProductID(string);
	void displayProductDescription(string);
	void displayUnitCost(float);

	void displaySubtotal(float);
	void displayTax(float);
	void displayTotal(float);

	void displayPaymentOptions();

	void displayCardConfirmation(int);

	void displayCashPaymentPrompt(bool);

	void displayAmountPaid(float);
	void displayAmountDue(float);
	void displayChange(float);

	void displayLine();

	int getUserSelection();
	void displayTwoDecimalFloat(float);

};

*/