#include "Item.h"

#include <string>

using namespace std;

Item::Item(const string id, const string description, const float price)
	: m_productID{ id }
	, m_productDescription{ description }
	, m_unitPrice{ price } {}

Item::Item(const Item& src) = default;

//Get item characteristics
string Item::getProductID() const { return m_productID; }
string Item::getProductDescription() const { return m_productDescription; }
float Item::getUnitPrice() const { return m_unitPrice; }