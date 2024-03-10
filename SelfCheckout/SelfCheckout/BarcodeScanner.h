#pragma once

# include <string>
# include <vector>

#include "Inventory.h"
#include "Cart.h"

class BarcodeScanner
{
	
public:

	//virtual ~BarcodeScanner();

	void scanItem(const int itemNumber);

	vector<string> getScannedItemIDs();

private:

	const Inventory m_itemInventory;
	Cart m_scannedItems;

	unsigned int m_scannedItemCount{ 0 };

};