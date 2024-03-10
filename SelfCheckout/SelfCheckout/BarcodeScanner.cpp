#include "BarcodeScanner.h"

void BarcodeScanner::scanItem(const int itemNumber) {
	const Item scannedItem{ getItem(itemNumber)};
	m_scannedItems.addItem(scannedItem);
	//m_scannedItems.addItem(m_itemInventory.getItem(itemNumber));

} 

const Item& BarcodeScanner::getItem(const int itemNumber) const {
	return m_itemInventory.getItem(itemNumber);
}