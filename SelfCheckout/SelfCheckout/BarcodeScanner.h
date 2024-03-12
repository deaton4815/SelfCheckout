#pragma once

# include <string>
# include <vector>

#include "Inventory.h"
#include "Cart.h"

class BarcodeScanner
{

public:

	void scanItem(const int itemNumber);
	void removeItem();

	vector<unsigned int> getScannedItemNumbers();
	vector<string> getScannedItemIDs();
	vector<string> getScannedItemDescriptions();
	vector<float> getScannedItemPrices();
	float getSubtotal();

	void resetCart();

private:

	const Inventory m_itemInventory;
	Cart m_scannedItems;

};