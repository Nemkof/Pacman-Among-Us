#pragma once
#include <SFML/Audio.hpp>
#include "level.h"
using namespace sf;
enum class Direction { left, right, up, down, stay };
class Entity {    
public:
    Direction direction;
    float dx = 0;
    float dy = 0;
    float x, y, w, h, startY, startX;
    float speed = 0;

    float player_sprites = 0; // Переменная для переключения спрайтов игрока

    Texture texture;
    Sprite sprite;
    std::string name;
    Entity(const Object& object);

    FloatRect getRect();
    FloatRect getRectForRotates();
    Sprite getSprite();
    float getX();
    float getY();
    std::string getDirection();

    // Обновляем спрайты игрока
    void updateSprites(float Dx, float time);
};






