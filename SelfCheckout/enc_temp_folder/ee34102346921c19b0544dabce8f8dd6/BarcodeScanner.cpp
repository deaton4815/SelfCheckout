#include "BarcodeScanner.h"

using namespace std;

void BarcodeScanner::scanItem(const int itemNumber) {
	m_scannedItems.addItem(m_itemInventory.getItem(itemNumber));
} 

vector<string> BarcodeScanner::getScannedItemIDs() {
	return m_scannedItemIDs;
}
vector<string> BarcodeScanner::getScannedItemDescriptions() { 
	return m_scannedItemDescriptions;
}
vector<float> BarcodeScanner::getScannedItemPrices() {
	return m_scannedItemPrices;
}

void BarcodeScanner::updateScannedIDs() {
	setUpdatedScannedIDs(getUpdatedScannedIDs());
}
void BarcodeScanner::updateScannedDescriptions() {
	setUpdatedScannedDescriptions(getUpdatedScannedDescriptions());
}
void BarcodeScanner::updatedScannedPrices() {
	setUpdatedScannedPrices(getUpdatedScannedPrices());
}

vector<string> BarcodeScanner::getUpdatedScannedIDs() {
	return m_scannedItems.getItemIDs();
}
vector<string> BarcodeScanner::getUpdatedScannedDescriptions() {
	return m_scannedItems.getItemDescriptions();
}
vector<float> BarcodeScanner::getUpdatedScannedPrices() {
	return m_scannedItems.getItemPrices();
}

void BarcodeScanner::setUpdatedScannedIDs(const vector<string>& ids) {
	m_scannedItemIDs = ids;
}
void BarcodeScanner::setUpdatedScannedDescriptions(const vector<string>& descriptions) {
	m_scannedItemDescriptions = descriptions;
}
void BarcodeScanner::setUpdatedScannedPrices(const vector<float>& prices) {
	m_scannedItemPrices = prices;
}