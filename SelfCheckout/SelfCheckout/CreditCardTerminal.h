#pragma once

#include <cstdlib>

class CreditCardTerminal
{
public:

	int makePayment();

private:

	int authorizePayment();
	int generateConfirmationCode();

};

