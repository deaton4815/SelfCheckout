#include "BarcodeScanner.h"

void BarcodeScanner::scanItem(const int itemNumber) {
	m_scannedItems.addItem(m_itemInventory.getItem(itemNumber));
} 