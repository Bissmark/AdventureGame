#include "Inventory.h"

Inventory::Inventory() {
	for (int i = 0; i < 5; i++) {
		items[i] = 0;
	}
	selectedItem = 0;
}

void Inventory::Draw() {
	DrawRectangle(0, 0, 100, 100, BLACK);
	DrawText("Inventory", 10, 10, 20, WHITE);
	DrawText(TextFormat("Item 1: %i", items[0]), 10, 40, 20, WHITE);
	DrawText(TextFormat("Item 2: %i", items[1]), 10, 70, 20, WHITE);
}

void Inventory::SelectItem() {
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

void Inventory::UseItem() {
	if (IsKeyPressed(KEY_U)) {
		items[selectedItem]--;
	}
}

