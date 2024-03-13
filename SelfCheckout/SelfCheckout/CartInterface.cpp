#include "CartInterface.h"

using namespace std;

CartInterface::CartInterface()
	: m_numberHeader{ "Item #" }
	, m_idHeader{ "Product ID" }
	, m_descriptionHeader{ "Product Description" }
	, m_costHeader{ "Unit Cost" }
	, m_headerSpacer{ "  " }
	, m_sizeNumberHeader{ m_numberHeader.size()}
	, m_sizeIDHeader{ m_idHeader.size() }
	, m_sizeDescriptionHeader{ m_descriptionHeader.size() }
	, m_sizeCostHeader{ m_costHeader.size() }
	, m_sizeHeaderSpacer{ m_headerSpacer.size() }
{}
	
void CartInterface::displayCart (vector<unsigned int> itemNumbers,
	vector<string> itemIDs, vector<string> itemDescriptions,
	vector<float> itemPrices, float subtotal) const {

	displayCartHeader();

	size_t itemCount{ itemNumbers.size() };
	for (size_t i{ 0 }; i < itemCount; ++i) {
		displayItem(itemNumbers[i], itemIDs[i],
			itemDescriptions[i], itemPrices[i]);
	}

	displayLine();

}

void CartInterface::displayCartHeader() const {
	cout << "\n";
	cout << m_numberHeader << m_headerSpacer;
	cout << m_idHeader << m_headerSpacer;
	cout << m_descriptionHeader << m_headerSpacer;
	cout << m_costHeader << endl;

	displayLine();
} 

void CartInterface::displayItem(unsigned int number, string id,
	string description, float price) const {

	displayColumn(number, m_sizeNumberHeader);
	displayColumn(id, m_sizeIDHeader);
	displayColumn(description, m_sizeDescriptionHeader); 
	displayColumn(price);

}

void CartInterface::displayColumn(unsigned int column, size_t sizeHeader) const {

	size_t sizeColumn{ getDigitCount(column) };
	string spacer{ getWhitespace(sizeHeader, sizeColumn) };

	cout << column << spacer;
}

void CartInterface::displayColumn(string column, size_t sizeHeader) const {

	string spacer{ getWhitespace(sizeHeader, column.size()) };
	cout << column << spacer;
}

void CartInterface::displayColumn(float column) const {
	cout << "$";
	displayTwoDecimalFloat(column);
	cout << endl;
}

string CartInterface::getWhitespace(size_t sizeHeader, size_t sizeEntry) const {
	size_t sizeWhitespace{ sizeHeader + m_sizeHeaderSpacer - sizeEntry };
	string whitespace(sizeWhitespace, ' ');
	return whitespace;
}

size_t CartInterface::getDigitCount(unsigned int number) const {
	size_t digitCount{ 0 };
	while (number != 0) {
		number = number / 10;
		++digitCount;
	}
	return digitCount;
}

void CartInterface::displayLine() const {

	size_t sizeTotal
		= m_sizeNumberHeader + m_sizeHeaderSpacer
		+ m_sizeIDHeader + m_sizeHeaderSpacer
		+ m_sizeDescriptionHeader + m_sizeHeaderSpacer
		+ m_sizeCostHeader;

	string line(sizeTotal, '-');
	cout << line << endl;
}

void CartInterface::displayTwoDecimalFloat(float value) const {
	cout << fixed << setprecision(2) << value;
}