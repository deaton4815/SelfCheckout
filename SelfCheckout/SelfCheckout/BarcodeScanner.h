#pragma once

#include "Item.h"
#include "Inventory.h"
#include "Cart.h"

class BarcodeScanner
{
	
public:

	void scanItem(const int itemNumber);

private:

	const Inventory m_itemInventory;
	Cart m_scannedItems;

	const Item& getItem(const int) const;


};