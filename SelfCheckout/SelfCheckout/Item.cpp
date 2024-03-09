#include "Item.h"

#include <string>

using namespace std;

/*
Item::Item()
	: m_productID{ "" }
	, m_productDescription{ "" }
	, m_unitPrice{ 0.f } {}
	*/

Item::Item(const string id, const string description, const float price)
	: m_productID{ id }
	, m_productDescription{ description }
	, m_unitPrice{ price } {}

Item::Item(const Item& src) = default;

string Item::getProductID() const { return m_productID; }

string Item::getProductDescription() const { return m_productDescription; }

float Item::getUnitPrice() const { return m_unitPrice; }