#include "ItemBar.h"

ItemBar::ItemBar() {
	for (int i = 0; i < 5; i++) {
		items[i] = 0;
	}
	selectedItem = 0;
}

void ItemBar::Draw() {
	const int itemBarWidth = 5 * 25 + 4 * 10; // 5 items * 25px width + 4 gaps * 10px
	const int itemBarHeight = 25; // Height of each item square
	const int itemBarX = (GetScreenWidth() - itemBarWidth) / 2; // Center the item bar
	const int itemBarY = GetScreenHeight() - itemBarHeight - 20; // 10px from the bottom

	for (int i = 0; i < 5; i++) {
		int itemX = itemBarX + i * (25 + 20); // 25px width + 10px gap between items
		Color itemColor = (i == selectedItem) ? RED : WHITE; // Highlight selected item

		DrawRectangle(itemX, itemBarY, 40, 40, itemColor);
	}
}

void ItemBar::SelectItem() {
	if (IsKeyPressed(KEY_ONE)) {
		selectedItem = 0;
	}
	else if (IsKeyPressed(KEY_TWO)) {
		selectedItem = 1;
	}
	else if (IsKeyPressed(KEY_THREE)) {
		selectedItem = 2;
	}
	else if (IsKeyPressed(KEY_FOUR)) {
		selectedItem = 3;
	}
	else if (IsKeyPressed(KEY_FIVE)) {
		selectedItem = 4;
	}
}

void ItemBar::UseItem() {
	if (IsKeyPressed(KEY_U)) {
		items[selectedItem]--;
	}
}