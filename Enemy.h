#pragma once

#ifndef ENEMY_H
#define ENEMY_H

#include <raylib.h>

class Enemy {
public:
    Vector2 position;
    float speed;
    Color color;

    Enemy();
    Enemy(Vector2 position, float speed, Color color);
    void Move();
    void Draw();
    void Destroy();
    void Movement(Vector2 position);
};

#endif