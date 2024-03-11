#include "Inventory.h"

#include <string>

using namespace std;

Inventory::Inventory()
	: m_meat01ID("Meat01")
	, m_meat01Description("T-Bone Steak")
	, m_meat01Price(7.99f)
	, m_meat01(m_meat01ID, m_meat01Description, m_meat01Price)

	, m_meat02ID("Meat02")
	, m_meat02Description("Tyson Fresh Chicken Wings")
	, m_meat02Price(10.00f)
	, m_meat02(m_meat02ID, m_meat02Description, m_meat02Price)

	, m_iceCream01ID("Icecream01")
	, m_iceCream01Description("Chocolate Ice Cream")
	, m_iceCream01Price(2.50f)
	, m_iceCream01(m_iceCream01ID, m_iceCream01Description, m_iceCream01Price)

	, m_iceCream02ID("Icecream02")
	, m_iceCream02Description("Vanilla Ice Cream")
	, m_iceCream02Price(2.50f)
	, m_iceCream02(m_iceCream02ID, m_iceCream02Description, m_iceCream02Price)

	, m_corn01ID("Corn01")
	, m_corn01Description("Fresh Sweet Corn")
	, m_corn01Price(2.00f)
	, m_corn01(m_corn01ID, m_corn01Description, m_corn01Price)

	, m_caseWaters01ID("Casewater01")
	, m_caseWaters01Description("24 Bottles 16-Ox of Deer Park Water")
	, m_caseWaters01Price(4.99f)
	, m_caseWater01(m_caseWaters01ID, m_caseWaters01Description, m_caseWaters01Price)

	, m_potatoChips01ID("Potatochips01")
	, m_potatoChips01Description("Plain Potato Chips")
	, m_potatoChips01Price(2.00f)
	, m_potatoChips01(m_potatoChips01ID, m_potatoChips01Description, m_potatoChips01Price)

	, m_potatoChips02ID("Potatochips02")
	, m_potatoChips02Description("Green Onion Potato Chips")
	, m_potatoChips02Price(2.00f)
	, m_potatoChips02(m_potatoChips02ID, m_potatoChips02Description, m_potatoChips02Price)

	, m_donuts01ID("Donuts01")
	, m_donuts01Description("Glazed Donutes One-Dozen")
	, m_donuts01Price(4.99f)
	, m_donuts01(m_donuts01ID, m_donuts01Description, m_donuts01Price)

	, m_sausage01ID("Sausage01")
	, m_sausage01Description("8-Sausage Pack")
	, m_sausage01Price(4.99f)
	, m_sausage01(m_sausage01ID, m_sausage01Description, m_sausage01Price)

	, m_eggs01ID("Eggs01")
	, m_eggs01Description("Dozen Eggs")
	, m_eggs01Price(3.00f)
	, m_eggs01(m_eggs01ID, m_eggs01Description, m_eggs01Price)

	, m_milk01ID("Milk01")
	, m_milk01Description("Gallon Milk")
	, m_milk01Price(4.00f)
	, m_milk01(m_milk01ID, m_milk01Description, m_milk01Price)
{
	//setFullMenu();
}

const Item Inventory::getItem(const int itemNumber) const {
	const ItemName name{ getItemName(itemNumber) };
	return identifyItem(name);
}

/*
void Inventory::setFullMenu() {
	m_itemIDsAll[0] = m_meat01ID;
	m_itemIDsAll[1] = m_meat02ID;
	m_itemIDsAll[2] = m_iceCream01ID;
	m_itemIDsAll[3] = m_iceCream02ID;
	m_itemIDsAll[4] = m_corn01ID;
	m_itemIDsAll[5] = m_caseWaters01ID;
	m_itemIDsAll[6] = m_potatoChips01ID;
	m_itemIDsAll[7] = m_potatoChips02ID;
	m_itemIDsAll[8] = m_donuts01ID;
	m_itemIDsAll[9] = m_sausage01ID;
	m_itemIDsAll[10] = m_eggs01ID;
	m_itemIDsAll[11] = m_milk01ID;

	m_itemDescriptionsAll[0] = m_meat01Description;
	m_itemDescriptionsAll[1] = m_meat02Description;
	m_itemDescriptionsAll[2] = m_iceCream01Description;
	m_itemDescriptionsAll[3] = m_iceCream02Description;
	m_itemDescriptionsAll[4] = m_corn01Description;
	m_itemDescriptionsAll[5] = m_caseWaters01Description;
	m_itemDescriptionsAll[6] = m_potatoChips01Description;
	m_itemDescriptionsAll[7] = m_potatoChips02Description;
	m_itemDescriptionsAll[8] = m_donuts01Description;
	m_itemDescriptionsAll[9] = m_sausage01Description;
	m_itemDescriptionsAll[10] = m_eggs01Description;
	m_itemDescriptionsAll[11] = m_milk01Description;

	m_itemPricesAll[0] = m_meat01Price;
	m_itemPricesAll[1] = m_meat02Price;
	m_itemPricesAll[2] = m_iceCream01Price;
	m_itemPricesAll[3] = m_iceCream02Price;
	m_itemPricesAll[4] = m_corn01Price;
	m_itemPricesAll[5] = m_caseWaters01Price;
	m_itemPricesAll[6] = m_potatoChips01Price;
	m_itemPricesAll[7] = m_potatoChips02Price;
	m_itemPricesAll[8] = m_donuts01Price;
	m_itemPricesAll[9] = m_sausage01Price;
	m_itemPricesAll[10] = m_eggs01Price;
	m_itemPricesAll[11] = m_milk01Price;
}
*/

Inventory::ItemName Inventory::getItemName(const int itemNumber) const {
	return static_cast<ItemName>(itemNumber);
}

const Item Inventory::identifyItem(Inventory::ItemName name) const {
	switch (name) {
	case ItemName::Meat01:
		return getMeat01();
		break;
	case ItemName::Meat02:
		return getMeat02();
		break;
	case ItemName::IceCream01:
		return getIceCream01();
		break;
	case ItemName::IceCream02:
		return getIceCream02();
		break;
	case ItemName::Corn01:
		return getCorn01();
		break;
	case ItemName::CaseWater01:
		return getCaseWater01();
		break;
	case ItemName::PotatoChips01:
		return getPotatoChips01();
		break;
	case ItemName::PotatoChips02:
		return getPotatoChips02();
		break;
	case ItemName::Donuts01:
		return getDonuts01();
		break;
	case ItemName::Sausage01:
		return getSausage01();
		break;
	case ItemName::Eggs01:
		return getEggs01();
		break;
	case ItemName::Milk01:
		return getMilk01();
		break;
	}
}

const Item Inventory::getMeat01() const { return m_meat01; }
const Item Inventory::getMeat02() const { return m_meat02; }
const Item Inventory::getIceCream01() const { return m_iceCream01; }
const Item Inventory::getIceCream02() const { return m_iceCream02; }
const Item Inventory::getCorn01() const { return m_corn01; }
const Item Inventory::getCaseWater01() const { return m_caseWater01; }
const Item Inventory::getPotatoChips01() const { return m_potatoChips01; }
const Item Inventory::getPotatoChips02() const { return m_potatoChips02; }
const Item Inventory::getDonuts01() const { return m_donuts01; }
const Item Inventory::getSausage01() const { return m_sausage01; }
const Item Inventory::getEggs01() const { return m_eggs01; }
const Item Inventory::getMilk01() const { return m_milk01; }