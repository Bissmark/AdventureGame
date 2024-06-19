#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

class Player {
public:
    Vector2 position;
    float speed;
    Color color;
    Rectangle rec;

    Player(Vector2 position, float speed, Color color);
    void Move();
    void Draw();
    void Interact();
    void Roll();
};

#endif