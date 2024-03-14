/*
* The portal interface serves as the opening interface
* for the user of the self checkout macnine.
* User selects either customer or employee portal.
*/
#pragma once
#include "SelectionMenu.h"

#include <iostream>

class PortalMenu : public SelectionMenu
{
private:

	void displayMenuHeader() const override;
	void displayMenuOptions() const override;
	void displayOpeningMessage() const;
};

