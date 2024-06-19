#include "Player.h"

Player::Player(Vector2 position, float speed, Color color) {
    this->position = position;
    this->speed = speed;
    this->color = color;
    this->rec = { position.x, position.y, 50, 50 };
}

void Player::Move() {
    if (IsKeyDown(KEY_RIGHT)) position.x += speed;
    if (IsKeyDown(KEY_LEFT)) position.x -= speed;
    if (IsKeyDown(KEY_UP)) position.y -= speed;
    if (IsKeyDown(KEY_DOWN)) position.y += speed;
    rec = { position.x, position.y, 50, 50 };
}

void Player::Draw() {
    DrawRectangleRec(rec, color);
}

void Player::Interact() {
	if (IsKeyDown(KEY_E)) {
		// Interact with something
	}
}

void Player::Roll() {
	if (IsKeyDown(KEY_SPACE)) {
		// Roll
	}
}