#pragma once
#include "SelectionMenu.h"
#include <iostream>

class ItemMenu : public SelectionMenu
{
private:
	void displayMenuHeader() const override;
	void displayMenuOptions() const override;
	void displayInputPrompt() const override;
};

