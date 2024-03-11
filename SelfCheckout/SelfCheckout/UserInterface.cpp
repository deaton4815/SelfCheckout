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

int UserInterface::getPaymentOption() {
	displayPaymentOptions();
	int selection{ getUserSelection() };
	return selection;
}

void UserInterface::displayCart(vector<unsigned int> itemNumbers,
	vector<string> itemIDs, vector<string> itemDescriptions,
	vector<float> itemPrices, float subtotal) {

	displayCartHeader();
	
	size_t itemCount{ itemNumbers.size() };
	for (size_t i{ 0 }; i < itemCount; ++i) {
		displayItem(itemNumbers[i], itemIDs[i],
			itemDescriptions[i], itemPrices[i]);
	}

	displaySubtotal(subtotal);
}

void UserInterface::displayFullPrice(float subtotal, float tax, float total) {
	cout << "\nAmount due:";
	displaySubtotal(subtotal);
	displayTax(tax);
	displayTotal(total);
}

void UserInterface::displayCardPayment(int code, float paid, float due) {

	displayCardConfirmation(code);
	displayAmountPaid(paid);
	displayAmountDue(due);

}

void UserInterface::displayActionPrompt() {
	cout << "\nPlease choose one of the following options.\n";
}

void UserInterface::displayAvailableActions() {
	cout << "\n1 - Scan new item." << endl;
	cout << "2 - Remove previous item selection." << endl;
	cout << "3 - Pay." << endl;
	
	cout << "0 - Terminate Program." << endl;

	cout << "\nEnter the number corresponding with your selection: ";

}

void UserInterface::displayAvailableItems() {
	cout << "\n\nAvailable Items:" << endl;
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

	cout << "\nEnter the number corresponding with your selection: ";
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

void UserInterface::displaySubtotal(float subtotal) {
	cout << "\nSubtotal: $";
	displayTwoDecimalFloat(subtotal);
	cout << endl;
	}

void UserInterface::displayTax(float tax) {
	cout << "Tax:      $";
	displayTwoDecimalFloat(tax);
	cout << endl;
}

void UserInterface::displayTotal(float total) {
	cout << "Total:    $";
	displayTwoDecimalFloat(total);
	cout << endl;
}

void UserInterface::displayPaymentOptions() {
	cout << "\nPayment options:" << endl;
	cout << "1 - Credit or debit." << endl;
	cout << "2 - Cash payment." << endl;
}

void UserInterface::displayCardConfirmation(int code) {
	cout << "\nPayment Authorized!" << endl;
	cout << "Confirmation Code: " << code << endl;
}

void UserInterface::displayAmountPaid(float amount) {
	cout << "\nAmount paid: $";
	displayTwoDecimalFloat(amount);
	cout << endl;
}

void UserInterface::displayAmountDue(float amount) {
	cout << "Remaining due: $";
	displayTwoDecimalFloat(amount);
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