#include "CreditCardTerminal.h"

int CreditCardTerminal::makePayment() {

	setConfirmationCode(authorizePayment());
	int confirmationCode{ getConfirmationCode() };
	return m_confirmationCode;
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
	int lowerBound{ 10000 };
	int upperBound{ 99999 };

	int confirmationCode = rand() % (upperBound - lowerBound + 1)
		+ lowerBound;
	return confirmationCode;
}

int CreditCardTerminal::getConfirmationCode() { return m_confirmationCode; }
void CreditCardTerminal::setConfirmationCode(int code) { m_confirmationCode = code; }