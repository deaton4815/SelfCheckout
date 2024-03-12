#include "BarcodeScanner.h"

using namespace std;

void BarcodeScanner::scanItem(const int itemNumber) {
	m_scannedItems.addItem(m_itemInventory.getItem(itemNumber));
}

void BarcodeScanner::removeItem() {
	m_scannedItems.removeItem();
}

vector<unsigned int> BarcodeScanner::getScannedItemNumbers() {
	return m_scannedItems.getItemNumbers();
}

vector<string> BarcodeScanner::getScannedItemIDs() {
	return m_scannedItems.getItemIDs();
}

vector<string> BarcodeScanner::getScannedItemDescriptions() {
	return m_scannedItems.getItemDescriptions();
}

vector<float> BarcodeScanner::getScannedItemPrices() {
	return m_scannedItems.getItemPrices();
}

float BarcodeScanner::getSubtotal() {
	return m_scannedItems.getSubtotal();
}

void BarcodeScanner::resetCart() { m_scannedItems.resetCart(); }