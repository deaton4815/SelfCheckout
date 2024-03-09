#include "Item.h"

#include <string>

using namespace std;

void Item::setProductID(string id) { m_productID = id; }

void Item::setProductDescription(string description) {
	m_productDescription = description;
}

void Item::setUnitPrice(float price) { m_unitPrice = price; }

string Item::getProductID() { return m_productID; }

string Item::getProductDescription() { return m_productDescription; }

float Item::getUnitPrice() { return m_unitPrice; }