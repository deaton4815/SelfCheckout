#include "UserInterface.h"

using namespace std;

/*
UserInterface::UserInterface() {
	displayOpeningMessage();
}
*/

void UserInterface::displayOpeningMessage() {
	cout << "Hello and welcome to self-checkout!" << endl << endl;
}

int UserInterface::getActionSelection() {

	displayActionPrompt();
	displayAvailableActions();
	int selection{ getUserSelection() };
	return selection;
}

int UserInterface::getItemSelection() {
	displayAvailableItems();
	int selection{ getUserSelection() };
	return selection;
}

void UserInterface::displayCart(vector<unsigned int> itemNumbers,
	vector<string> itemIDs, vector<string> itemDescriptions,
	vector<float> itemPrices, float subtotal, float tax, float total) {

	displayCartHeader();
	
	size_t itemCount{ itemNumbers.size() };
	for (size_t i{ 0 }; i < itemCount; ++i) {
		displayItem(itemNumbers[i], itemIDs[i],
			itemDescriptions[i], itemPrices[i]);
	}

	displayPrice(subtotal, tax, total);
}

void UserInterface::displayActionPrompt() {
	cout << "Please choose one of the following options.\n";
	cout << "Enter the number that corresponds with your selection." << endl;
}

void UserInterface::displayAvailableActions() {
	cout << "1 - Scan new item." << endl;
	
	cout << "0 - Terminate Program." << endl;
}

void UserInterface::displayAvailableItems() {
	cout << "Available Items:" << endl;
	cout << "Enter the number that corresponds with your selection." << endl;
	cout << "1 - Meat01" << endl;
	cout << "2 - Meat02" << endl;
	cout << "3 - Icecream01" << endl;
	cout << "4 - Icecream02" << endl;
	cout << "5 - Corn01" << endl;
	cout << "6 - Casewater01" << endl;
	cout << "7 - Potatochips01" << endl;
	cout << "8 - Potatochips02" << endl;
	cout << "9 - Donuts01" << endl;
	cout << "10 - Sausage01" << endl;
	cout << "11 - Eggs01" << endl;
	cout << "12 - Milk01" << endl;
}

void UserInterface::displayItem(unsigned int number, string id,
	string description, float price) {
	displayItemNumber(number);
	displayProductID(id);
	displayProductDescription(description);
	displayUnitCost(price);
}

void UserInterface::displayCartHeader() {
	cout << "Item # | Product ID    | Product Description";
	cout << "                 | Unit Cost" << endl;
	cout << "--------------------------------------------";
	cout << "----------------------------" << endl;
} 

void UserInterface::displayItemNumber(unsigned int number) {
	cout << number;
	cout << "    ";
	if (number < 100) {
		cout << " ";
	}
	if (number < 10) {
		cout << " ";
	}
	cout << "|";
}

void UserInterface::displayProductID(string id) {
	cout << " " << id;

	int remainingWhitespace = 14 - id.length();
	switch (remainingWhitespace) {
	case 1:
		cout << " ";
		break;
	case 3:
		cout << "   ";
		break;
	case 4:
		cout << "    ";
		break;
	case 5:
		cout << "     ";
		break;
	case 6:
		cout << "      ";
		break;
	case 8:
	default:
		cout << "        ";
		break;
	}
	cout << "|";
}

void UserInterface::displayProductDescription(string description) {
	cout << " " << description;

	int remainingWhitespace = 36 - description.length();
	switch (remainingWhitespace) {
	case 1:
		cout << " ";
		break;
	case 11:
		cout << "           ";
		break;
	case 12:
		cout << "            ";
		break;
	case 13:
		cout << "             ";
		break;
	case 17:
		cout << "                 ";
		break;
	case 18:
		cout << "                  ";
		break;
	case 19:
		cout << "                   ";
		break;
	case 20:
		cout << "                    ";
		break;
	case 22:
		cout << "                      ";
		break;
	case 24:
		cout << "                        ";
		break;
	case 25:
		cout << "                         ";
		break;
	case 26:
		cout << "                          ";
		break;
	}
	cout << "|";
}

void UserInterface::displayUnitCost(float price) {
	cout << " $";
	displayTwoDecimalFloat(price);
	cout << endl;
}

void UserInterface::displayPrice(float subtotal, float tax, float total) {
	cout << "\nSubtotal: $";
	displayTwoDecimalFloat(subtotal);
	cout << endl;

	cout << "Tax:      $";
	displayTwoDecimalFloat(tax);
	cout << endl;

	cout << "Total:    $";
	displayTwoDecimalFloat(total);
	cout << endl;
}

int UserInterface::getUserSelection() {
	int selection{ 0 };
	cin >> selection;
	return selection;
}

void UserInterface::displayTwoDecimalFloat(float value) {
	cout << fixed << setprecision(2) << value;
}