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

	void displayCart(vector<unsigned int>, vector<string>,
		vector<string>, vector<float>, float, float, float);

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

	void displayPrice(float, float, float);

	int getUserSelection();

	void displayTwoDecimalFloat(float);

};

