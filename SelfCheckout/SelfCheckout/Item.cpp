#include "Item.h"

#include <string>

using namespace std;

Item::Item(string id, string description, float price)
	: m_productID{ id }
	, m_productDescription{ description }
	, m_unitPrice{ price } {}

string Item::getProductID() { return m_productID; }

string Item::getProductDescription() { return m_productDescription; }

float Item::getUnitPrice() { return m_unitPrice; }