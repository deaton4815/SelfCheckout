#include "Cart.h"

void Cart::addItem(const Item& item) {
	//const Item scannedItem{ item };
	m_scannedItems.push_back(item);
	}