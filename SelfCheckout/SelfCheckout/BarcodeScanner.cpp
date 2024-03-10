#include "BarcodeScanner.h"

using namespace std;

void BarcodeScanner::scanItem(const int itemNumber) {
	m_scannedItems.addItem(m_itemInventory.getItem(itemNumber));
} 

vector<string> BarcodeScanner::getScannedItemIDs() { return m_scannedItemIDs; }

vector<string> BarcodeScanner::getScannedItemDescriptions() { return m_scannedItemDescriptions; }

vector<float> BarcodeScanner::getScannedItemPrices() { return m_scannedItemPrices; }

void BarcodeScanner::updateCartInfo() {

	m_scannedItemIDs = m_scannedItems.getItemIDs();
	m_scannedItemDescriptions = m_scannedItems.getItemDescriptions();
	m_scannedItemPrices = m_scannedItems.getItemPrices();

}

