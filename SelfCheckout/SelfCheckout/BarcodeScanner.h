/*
* Class acts as the barcode scanner, acting as the engine for the inventory and cart.
* Functionality includes adding appropriate items to the cart from the inventory
* and retrieving information from the cart.
*/

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

	vector<unsigned int> getScannedItemNumbers() const;
	vector<string> getScannedItemIDs() const;
	vector<string> getScannedItemDescriptions() const;
	vector<float> getScannedItemPrices() const;
	float getSubtotal() const;

	void resetCart();

private:

	const Inventory m_itemInventory;
	Cart m_scannedItems;

};