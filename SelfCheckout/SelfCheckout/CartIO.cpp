#include "CartIO.h"

using namespace std;
	
// Displays cart contents
void CartIO::displayCart (const vector<unsigned int>& itemNumbers,
	const vector<string>& itemIDs, const vector<string>& itemDescriptions,
	const vector<float>& itemPrices) const {

	displayCartHeader();

	size_t itemCount{ itemNumbers.size() };
	for (size_t i{ 0 }; i < itemCount; ++i) {
		displayItem(itemNumbers[i], itemIDs[i],
			itemDescriptions[i], itemPrices[i]);
	}

	displayLine();
}

// Displays a line that is the same width as the cart display
void CartIO::displayLine() const {

	size_t sizeTotal
		= m_sizeNumberColumn + m_sizeColumnSpacer
		+ m_sizeIDColumn + m_sizeColumnSpacer
		+ m_sizeDescriptionColumn + m_sizeColumnSpacer
		+ m_sizeCostColumn;

	string line(sizeTotal, '-');
	cout << line << endl;
}

// Displays cart property headers
void CartIO::displayCartHeader() const {
	cout << "\n";
	displayColumn(m_numberHeader, m_sizeNumberColumn);
	displayColumn(m_idHeader, m_sizeIDColumn);
	displayColumn(m_descriptionHeader, m_sizeDescriptionColumn);
	cout << m_costHeader << endl;

	displayLine();
}

// Displays the properties of a single item
void CartIO::displayItem(unsigned int number,
	string id, string description, float price) const {

	//size_t size{ m_sizeNumberHeader };
	displayColumn(number, m_sizeNumberColumn);
	displayColumn(id, m_sizeIDColumn);
	displayColumn(description, m_sizeDescriptionColumn);
	displayColumn(price);

}

// Displays item number
void CartIO::displayColumn(const unsigned int column, size_t sizeHeader) const {

	size_t sizeColumn{ getDigitCount(column) };
	string spacer{ getWhitespace(sizeHeader, sizeColumn) };

	cout << column << spacer;
}

// Displays item ID and description
void CartIO::displayColumn(string column, size_t sizeHeader) const {

	string spacer{ getWhitespace(sizeHeader, column.size()) };
	cout << column << spacer;
}

// Displays unit price
void CartIO::displayColumn(float column) const {
	cout << "$";
	displayTwoDecimalFloat(column);
	cout << endl;
}

// Calculates whitespace needed to line up menu display
string CartIO::getWhitespace(const size_t sizeHeader, const size_t sizeEntry) const {
	size_t sizeWhitespace{ sizeHeader + m_sizeColumnSpacer - sizeEntry };
	string whitespace(sizeWhitespace, ' ');
	return whitespace;
}

// Gets digits in item number to line up menu display
size_t CartIO::getDigitCount(unsigned int number) const {
	size_t digitCount{ 0 };
	while (number != 0) {
		number = number / 10;
		++digitCount;
	}
	return digitCount;
}

void CartIO::displayTwoDecimalFloat(const float value) const {
	cout << fixed << setprecision(2) << value;
}