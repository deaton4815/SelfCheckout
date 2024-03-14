#include "SCOControlCenter.h"

using namespace std;

//Control center alerted if change is too low
//Executes low-change protocol
float SCOControlCenter::executeLowChange(float changeLevel) {
	displayLowChangeMessage(changeLevel);
	float addedChange{ getMoreChange() };
	return addedChange;
}

//Displays low-change error message on SCO Control Center
void SCOControlCenter::displayLowChangeMessage(float changeLevel) const {
	cout << "\n\n--------------------SCO CONTROL CENTER--------------------";
	cout << "\nAlert! Change has fallen to $";
	displayTwoDecimalFloat(changeLevel);
	cout << endl;
}

//Prompts for more change. Machine services are suspended
//until enough change has been added
float SCOControlCenter::getMoreChange() {
	float addedChange{ 0 };
	cout << "Enter more change to continue service." << endl;
	cout << "Amount Entered: $";
	cin >> addedChange;
	cout << "\n\n----------------------------------------------------------";
	return addedChange;
}

void SCOControlCenter::displayTwoDecimalFloat(float value) const {
	cout << fixed << setprecision(2) << value;
}