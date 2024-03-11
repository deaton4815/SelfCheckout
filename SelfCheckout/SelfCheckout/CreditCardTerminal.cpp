#include "CreditCardTerminal.h"

int CreditCardTerminal::makePayment() {

	authorizePayment();
	int confirmationCode{ generateConfirmationCode() };
	return confirmationCode;

}

int CreditCardTerminal::authorizePayment() {

	int confirmationCode{ 0 };

	bool paymentAuthorized{ 1 };
	if (paymentAuthorized) {
		confirmationCode = generateConfirmationCode();
	}
	else {
		confirmationCode = 0;
	}
	return confirmationCode;
}

int CreditCardTerminal::generateConfirmationCode() {
	int N{ 100000 };
	int confirmationCode = rand() % N;
	return confirmationCode;
}