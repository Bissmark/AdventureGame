#pragma once

#ifndef ITEMBAR_H
#define ITEMBAR_H

#include <raylib.h>

class ItemBar {
	public:
	int items[5];
	int selectedItem;

	ItemBar();
	void Draw();
	void SelectItem();
	void UseItem();
};

#endif