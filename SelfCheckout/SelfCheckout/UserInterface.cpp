#include "UserInterface.h"

using namespace std;

int UserInterface::getPortalSelection() { return m_portal.getMenuSelection(); }







/*
int UserInterface::getPortalSelection() {
	displayOpeningMessage();
	displayPortalPrompts();
	int selection{ getUserSelection() };
	return selection;
}

int UserInterface::getCustomerSelection() {
	displayCustomerPrompt();
	int selection{ getUserSelection() };
	return selection;
}

int UserInterface::getEmployeeSelection() {
	displayEmployeePrompt();
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

float UserInterface::getCash(bool isFirst) {

	float cash{ 0.f };

	displayCashPaymentPrompt(isFirst);
	cin >> cash;
	return cash;
}

void UserInterface::displayReceiptHeader() {
	displayLine();
	cout << "Please take your receipt:" << endl;
	displayLine();
}

void UserInterface::displayReceiptFooter() {
	displayLine();
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

void UserInterface::displayCashPayment(float paid, float due, float change) {

	displayAmountPaid(paid);
	displayAmountDue(due);
	displayChange(change);

}

void UserInterface::displayOpeningMessage() {
	cout << "Hello and welcome to self-checkout!" << endl;
}

void UserInterface::displayPortalPrompts() {
	cout << "\nPlease select one of the following:" << endl;
	cout << "1 - Customer Portal" << endl;
	cout << "2 - Employee Portal" << endl;

	cout << "\n0 - Terminate Program" << endl;

	cout << "\nEnter selection number: ";
}

void UserInterface::displayCustomerPrompt() {
	cout << "\nPlease choose one of the following options:\n";

	cout << "\n1 - Scan new item" << endl;
	cout << "2 - Remove previous item selection" << endl;
	cout << "3 - Pay" << endl;

	cout << "\n0 - Return" << endl;

	cout << "\nEnter selection number: ";
}

void UserInterface::displayEmployeePrompt() {
	cout << "\nPlease choose one of the following options:\n";

	cout << "\n1 - Empty cash purchase repository" << endl;

	cout << "\n0 - Return." << endl;

	cout << "\nEnter selection number: ";
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

	cout << "\nEnter item number: ";
}

void UserInterface::displayItem(unsigned int number, string id,
	string description, float price) {
	displayItemNumber(number);
	displayProductID(id);
	displayProductDescription(description);
	displayUnitCost(price);
}

void UserInterface::displayCartHeader() {
	cout << "\nItem # | Product ID    | Product Description";
	cout << "                 | Unit Cost";
	displayLine();
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

	size_t remainingWhitespace = 14 - id.length();
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

	size_t remainingWhitespace = 36 - description.length();
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
	cout << "1 - Credit or debit" << endl;
	cout << "2 - Cash payment" << endl;

	cout << "\n0 - Return" << endl;
	cout << "\nEnter selection number: ";
}

void UserInterface::displayCardConfirmation(int code) {
	cout << "Confirmation Code: " << code << endl;
}

void UserInterface::displayCashPaymentPrompt(bool isFirst) {
	if (isFirst) {
		cout << "\nPlease input cash amount entered: $";
	}
	else {
		cout << "\nNot enough! Please enter more cash: $";
	}
}

void UserInterface::displayAmountPaid(float paid) {
	cout << "\nAmount paid: $";
	displayTwoDecimalFloat(paid);
	cout << endl;
}

void UserInterface::displayAmountDue(float due) {
	cout << "Remaining due: $";
	displayTwoDecimalFloat(due);
	cout << endl;
}

void UserInterface::displayChange(float change) {
	cout << "Change dispensed: $";
	displayTwoDecimalFloat(change);
	cout << endl;
}

void UserInterface::emptyCashPurchasesDisplay(float cash) {
	cout << "\nEmptying cash repository...Checkout Service Paused." << endl;
	cout << "Cash dispensed: $";
	displayTwoDecimalFloat(cash);
	cout << endl;

	int startButton{ 0 };
	do {
		cout << "\nEnter 1 to resume service:";
		cin >> startButton;
	} while (startButton != 1);
}

void UserInterface::displayLine() {
	cout << "\n--------------------------------------------";
	cout << "----------------------------" << endl;
}
int UserInterface::getUserSelection() {
	int selection{ 0 };
	cin >> selection;
	return selection;
}

void UserInterface::displayTwoDecimalFloat(float value) {
	cout << fixed << setprecision(2) << value;
}
*/