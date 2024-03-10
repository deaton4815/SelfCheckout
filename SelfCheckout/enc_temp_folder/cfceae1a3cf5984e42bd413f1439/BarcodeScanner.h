#pragma once

# include <string>
# include <vector>

#include "Inventory.h"
#include "Cart.h"

class BarcodeScanner
{
	
public:

	void scanItem(const int itemNumber);

	vector<string> getScannedItemIDs();
	vector<string> getScannedItemDescriptions();
	vector<float> getScannedItemPrices();

private:

	const Inventory m_itemInventory;
	Cart m_scannedItems;

	vector<string> m_scannedItemIDs;
	vector<string> m_scannedItemDescriptions;
	vector<float> m_scannedItemPrices;

	void updateScannedIDs();
	void updateScannedDescriptions();
	void updatedScannedPrices();

	vector<string> getUpdatedScannedIDs();
	vector<string> getUpdatedScannedDescriptions();
	vector<float> getUpdatedScannedPrices();

	void setUpdatedScannedIDs(const vector<string>&);
	void setUpdatedScannedDescriptions(const vector<string>&);
	void setUpdatedScannedPrices(const vector<float>&);
	

};