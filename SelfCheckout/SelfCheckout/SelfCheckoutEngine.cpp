#include "SelfCheckoutEngine.h"

//void SelfCheckoutEngine::executeUserSelection()

void SelfCheckoutEngine::executeItemSelection(const int itemNumber) {

	scanItem(itemNumber);
	updateSubtotal();

}

void SelfCheckoutEngine::scanItem(const int itemNumber) {
	m_scoScanner.scanItem(itemNumber);
}

void SelfCheckoutEngine::updateSubtotal() {
	m_subtotal = m_scoScanner.getSubtotal();
}