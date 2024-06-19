#include "Player.h"
#include "Enemy.h"
#include "ItemBar.h"

int main() {
	// Initialization
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	ToggleFullscreen();

	Texture2D background = LoadTexture("resources/background.png");

	Player player = Player({ 0, 0 }, 5, RED);
	Enemy enemy = Enemy({ 400.0f - 25, 0 }, 1, BLUE);
	ItemBar ItemBar;

	Camera2D camera = { 0 };
	camera.target = Vector2{ player.position.x, player.position.y };
	camera.offset = Vector2{ screenWidth / 2.0f, screenHeight / 2.0f };
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

	// Main game loop
	while (!WindowShouldClose()) {  // Detect window close button or ESC key
		// Update

		player.Move();
		enemy.Movement(player.position);

		camera.target = player.position;

		// Update camera zoom with mouse wheel
		float mouseWheelMove = GetMouseWheelMove();
		if (mouseWheelMove != 0) {
			camera.zoom += mouseWheelMove * 0.05f; // Adjust zoom speed to your liking
			// Clamp the camera zoom to prevent it from inverting or becoming too large
			if (camera.zoom < 0.1f) camera.zoom = 0.1f;
			if (camera.zoom > 3.0f) camera.zoom = 3.0f;
		}

		// Draw

		BeginDrawing();

		Vector2 backgroundPos = { -player.position.x + screenWidth / 2.0f, -player.position.y + screenHeight / 2.0f };
		DrawTexture(background, backgroundPos.x, backgroundPos.y, WHITE);

			ItemBar.Draw();

		BeginMode2D(camera);
			player.Draw();
			enemy.Draw();

		EndMode2D();
		EndDrawing();

	}

	// De-Initialization

	CloseWindow();        // Close window and OpenGL context

	return 0;

	}