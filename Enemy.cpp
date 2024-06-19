#include "Enemy.h"

Enemy::Enemy() {
    position = { 400.0f - 25, 0 }; // Assuming screenWidth is 800 for simplicity
    speed = 1;
    color = RED;
}

Enemy::Enemy(Vector2 position, float speed, Color color) {
    this->position = position;
    this->speed = speed;
    this->color = color;
}

void Enemy::Move() {
    position.y += speed;
}

void Enemy::Draw() {
    DrawRectangle(position.x, position.y, 50, 50, color);
}

void Enemy::Destroy() {
    position = { 400.0f - 25, 0 }; // Reset position, assuming screenWidth is 800 for simplicity
}

void Enemy::Movement(Vector2 playerPosition) {
	if (position.y > 450) {
		Destroy();
	}
	else {
        // Basic AI Movement towards the player
        if (position.x < playerPosition.x) {
            position.x += speed; // Move right towards the player
        }
        else if (position.x > playerPosition.x) {
            position.x -= speed; // Move left towards the player
        }

        if (position.y < playerPosition.y) {
            position.y += speed; // Move down towards the player
        }
        else if (position.y > playerPosition.y) {
            position.y -= speed; // Move up towards the player
        }
    }
}