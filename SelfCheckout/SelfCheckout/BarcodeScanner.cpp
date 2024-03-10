#include "BarcodeScanner.h"

using namespace std;

void BarcodeScanner::scanItem(const int itemNumber) {
	m_scannedItems.addItem(m_itemInventory.getItem(itemNumber));
} 

vector<string> BarcodeScanner::getScannedItemIDs() {
	updateScannedIDs();
	return m_scannedItemIDs;
}
vector<string> BarcodeScanner::getScannedItemDescriptions() { 
	updateScannedDescriptions();
	return m_scannedItemDescriptions;
}
vector<float> BarcodeScanner::getScannedItemPrices() {
	updateScannedPrices();
	return m_scannedItemPrices;
}

void BarcodeScanner::updateScannedIDs() {
	m_scannedItemIDs = m_scannedItems.getItemIDs();
}
void BarcodeScanner::updateScannedDescriptions() {
	m_scannedItemDescriptions = m_scannedItems.getItemDescriptions();
}
void BarcodeScanner::updateScannedPrices() {
	m_scannedItemPrices = m_scannedItems.getItemPrices();
}