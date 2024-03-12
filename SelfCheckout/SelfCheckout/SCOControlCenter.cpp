#include "SCOControlCenter.h"

using namespace std;

float SCOControlCenter::executeLowChange(float changeLevel) {
	displayLowChangeMessage(changeLevel);
	float addedChange{ getMoreChange() };
	return addedChange;
}

void SCOControlCenter::displayLowChangeMessage(float changeLevel) {
	cout << "\n\n--------------------SCO CONTROL CENTER--------------------";
	cout << "\nAlert! Change has fallen to $";
	displayTwoDecimalFloat(changeLevel);
	cout << endl;
}

float SCOControlCenter::getMoreChange() {
	float addedChange{ 0 };
	cout << "Enter more change to continue service." << endl;
	cout << "Amount Entered: $";
	cin >> addedChange;
	return addedChange;
}

void SCOControlCenter::displayTwoDecimalFloat(float value) {
	cout << fixed << setprecision(2) << value;
}