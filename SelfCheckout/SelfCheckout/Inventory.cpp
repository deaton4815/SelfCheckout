#include "Inventory.h"

#include <string>

#include "Item.h"

using namespace std;

Inventory::Inventory()
	: m_meat01ID{ "Meat01" }
	, m_meat01Description{ "T-Bone Steak" }
	, m_meat01Price{ 7.99 }
	, m_meat01(m_meat01ID, m_meat01Description, m_meat01Price)

	, m_meat02ID{ "Meat02" }
	, m_meat02Description{ "Tyson Fresh Chicken Wings" }
	, m_meat02Price{ 10.00 }
	, m_meat02(m_meat02ID, m_meat02Description, m_meat02Price)

	, m_iceCream01ID{ "Icecream01" }
	, m_iceCream01Description{ "Chocolate Ice Cream" }
	, m_iceCream01Price{ 2.50 }
	, m_iceCream01(m_iceCream01ID, m_iceCream01Description, m_iceCream01Price)

	, m_iceCream02ID{ "Icecream02" }
	, m_iceCream02Description{ "Vanilla Ice Cream" }
	, m_iceCream02Price{ 2.50 }
	, m_iceCream02(m_iceCream02ID, m_iceCream02Description, m_iceCream02Price)

	, m_corn01ID{ "Corn01" }
	, m_corn01Description{ "Fresh Sweet Corn" }
	, m_corn01Price{ 2.00 }
	, m_corn01(m_corn01ID, m_corn01Description, m_corn01Price)

	, m_caseWaters01ID{ "Casewater" }
	, m_caseWaters01Description{ "24 Bottles 16-Ox of Deer Park Water" }
	, m_caseWaters01Price{ 4.99 }
	, m_caseWater01(m_caseWaters01ID, m_caseWaters01Description, m_caseWaters01Price)

	, m_potatoChips01ID{ "Potatochips01" }
	, m_potatoChips01Description{ "Plain Potato Chips" }
	, m_potatoChips01Price{ 2.00 }
	, m_potatoChips01(m_potatoChips01ID, m_potatoChips01Description, m_potatoChips01Price)

	, m_potatoChips02ID{ "Potatochips02" }
	, m_potatoChips02Description{ "Green Onion Potato Chips" }
	, m_potatoChips02Price{ 2.00 }
	, m_potatoChips02(m_potatoChips02ID, m_potatoChips02Description, m_potatoChips02Price)
	
	, m_donuts01ID{ "Donuts01" }
	, m_donuts01Description{ "Glazed Donutes One-Dozen" }
	, m_donuts01Price{ 4.99 }
	, m_donuts01(m_donuts01ID, m_donuts01Description, m_donuts01Price)

	, m_sausage01ID{ "Sausage01" }
	, m_sausage01Description{ "8-Sausage Pack" }
	, m_sausage01Price{ 4.99 }
	, m_sausage01(m_sausage01ID, m_sausage01Description, m_sausage01Price)

	, m_eggs01ID{ "Eggs01" }
	, m_eggs01Description{ "Dozen Eggs" }
	, m_eggs01Price{ 3.00 }
	, m_eggs01(m_eggs01ID, m_eggs01Description, m_eggs01Price)

	, m_milk01ID{ "Milk01" }
	, m_milk01Description{ "Gallon Milk" }
	, m_milk01Price{ 4.00 }
	, m_milk01(m_milk01ID, m_milk01Description, m_milk01Price)
{}