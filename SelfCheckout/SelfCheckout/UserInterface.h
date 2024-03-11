#pragma once

#include <iostream>

class UserInterface
{

public:

	//UserInterface();

	void displayOpeningMessage();

	int getActionSelection();
	int getItemSelection();

private:

	void displayActionPrompt();
	void displayAvailableActions();
	
	void displayAvailableItems();

	int getUserSelection();

};

