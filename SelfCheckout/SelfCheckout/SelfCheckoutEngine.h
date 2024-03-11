#pragma once

#include "BarcodeScanner.h"

class SelfCheckoutEngine
{

private:
	//unsigned int getUserSelection();
	//void executeUserSelection();
	BarcodeScanner m_scoScanner;

	float m_subtotal{ 0.f };

	void executeItemSelection(const int);
	void scanItem(const int);
	void updateSubtotal();
};