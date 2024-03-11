#pragma once

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class UserInterface
{

public:

	//UserInterface();

	void displayOpeningMessage();

	int getActionSelection();
	int getItemSelection();
	int getPaymentOption();

	void displayCart(vector<unsigned int>, vector<string>,
		vector<string>, vector<float>, float);

	void displayFullPrice(float, float, float);

	void displayCardPayment(int, float, float);

private:

	void displayActionPrompt();
	void displayAvailableActions();
	
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

	void displayAmountPaid(float);
	void displayAmountDue(float);

	int getUserSelection();
	void displayTwoDecimalFloat(float);

};

