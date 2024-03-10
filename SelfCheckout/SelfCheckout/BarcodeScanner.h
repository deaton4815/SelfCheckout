#pragma once

# include <string>
# include <vector>

#include "Inventory.h"
#include "Cart.h"

class BarcodeScanner
{
	
public:

	void scanItem(const int itemNumber);

	vector<unsigned int> getScannedItemNumbers();
	vector<string> getScannedItemIDs();
	vector<string> getScannedItemDescriptions();
	vector<float> getScannedItemPrices();
	float getSubtotal();

private:

	const Inventory m_itemInventory;
	Cart m_scannedItems;

	vector<unsigned int> m_scannedItemNumbers;
	vector<string> m_scannedItemIDs;
	vector<string> m_scannedItemDescriptions;
	vector<float> m_scannedItemPrices;
	float m_cartSubtotal{ 0.f };

	void updateScannedNumbers();
	void updateScannedIDs();
	void updateScannedDescriptions();
	void updateScannedPrices();
	void updateSubtotal();
};