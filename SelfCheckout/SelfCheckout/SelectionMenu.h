#pragma once

#include <iostream>

class SelectionMenu
{

public:

	int getMenuSelection();

private:

	int m_selection{ 0 };

	virtual void displayMenuHeader() const;
	virtual void displayMenuOptions() const = 0;
	virtual void displayInputPrompt() const;

	int getUserInput();

	void setSelection(int);
};

