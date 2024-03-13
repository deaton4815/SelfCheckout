#include "CreditCardTerminal.h"

//Executes payment authorization process
int CreditCardTerminal::makePayment() {

	setConfirmationCode(authorizePayment());
	int confirmationCode{ getConfirmationCode() };
	return m_confirmationCode;
}

//Authorizes payment and returns 5-digit confirmation code
int CreditCardTerminal::authorizePayment() const {

	int confirmationCode{ 0 };

	bool paymentAuthorized{ 1 };//Hardcoded based on assumption that card payment is successful
	if (paymentAuthorized) {
		confirmationCode = generateConfirmationCode();
	}
	else {
		confirmationCode = 0;
	}
	return confirmationCode;
}

//Generates random 5-digit confirmation code
int CreditCardTerminal::generateConfirmationCode() const {
	int lowerBound{ 10000 };
	int upperBound{ 99999 };

	int confirmationCode = rand() % (upperBound - lowerBound + 1)
		+ lowerBound;
	return confirmationCode;
}

int CreditCardTerminal::getConfirmationCode() const { return m_confirmationCode; }
void CreditCardTerminal::setConfirmationCode(int code) { m_confirmationCode = code; }