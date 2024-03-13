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
}

void CartInterface::displayCartHeader() const {
	cout << "\n";
	cout << m_numberHeader << m_headerSpacer;
	cout << m_idHeader << m_headerSpacer;
	cout << m_descriptionHeader << m_headerSpacer;
	cout << m_costHeader << endl;

	displayLine();
} 

void CartInterface::displayNumber(unsigned int number) {

	size_t sizeNumber{ getDigitCount(number) };
	string spacer{ getWhitespace(m_sizeNumberHeader, sizeNumber) };

	cout << number << spacer;
}

void CartInterface::displayStringcolumn(string header, string column) {

	string spacer{ getWhitespace(m_sizeIDHeader, id.size()) };
	cout << id << spacer;
}

void CartInterface::displayDescription(string description) {

	string spacer{ getWhitespace(m_sizeDescriptionHeader, description.size()) };
	cout << description << spacer;
}
string CartInterface::getWhitespace(size_t sizeHeader, size_t sizeEntry) {
	size_t sizeWhitespace{ sizeHeader + m_sizeHeaderSpacer - sizeEntry };
	string whitespace(sizeWhitespace, ' ');
	return whitespace;
}

size_t CartInterface::getDigitCount(unsigned int number) {
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