#pragma once
#include <SFML/Audio.hpp>
#include "level.h"
using namespace sf;
class Entity {    
public:
    enum Direction { left, right, up, down, stay } state;
    std::vector<Object> obj; // Вектор объектов карты
    float dx = 0;
    float dy = 0;
    float x, y;
    float speed = 0;
    int w = 72, h = 90; // Ширина и высота тайла
    float player_sprites = 0; // Переменная для переключения спрайтов игрока
    float startX;
    float startY;

    Texture texture;
    Sprite sprite;
    std::string name;
    Entity(Object object);

    FloatRect getRect();
    Sprite getSprite();
    float getX();
    float getY();
    std::string getDirection();

    /// Обновляем спрайты игрока
    void updateSprites(float Dx, float time);
};






