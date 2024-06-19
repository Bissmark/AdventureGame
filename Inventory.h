#pragma once

#ifndef INVENTORY_H
#define INVENTORY_H

#include <raylib.h>

class Inventory {
	public:
	int items[5];
	int selectedItem;

	Inventory();
	void Draw();
	void SelectItem();
	void UseItem();
};

#endif