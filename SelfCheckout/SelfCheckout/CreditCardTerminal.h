/*
* Class processes credit and debit card payments.
* Returns 5-digit confirmation code
*/
#pragma once

#include <cstdlib>
#include <iostream>

class CreditCardTerminal
{
public:

	int makePayment();

private:

	int m_confirmationCode{ 0 };

	int authorizePayment() const;
	int generateConfirmationCode() const;

	int getConfirmationCode() const;
	void setConfirmationCode(int);

};

