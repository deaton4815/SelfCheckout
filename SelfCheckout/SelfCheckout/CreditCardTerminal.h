#pragma once

#include <cstdlib>

class CreditCardTerminal
{
public:

	int makePayment();

private:

	int m_confirmationCode{ 0 };

	int authorizePayment();
	int generateConfirmationCode();

	int getConfirmationCode();
	void setConfirmationCode(int);

};

