#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"
class Enemy: public Entity{
private:
    Direction lastDir;
    std::vector<Object> rotates;
    std::vector<Object> solids; // Вектор объектов карты
    //enum { Chase, Scatter, Frightened } status;
public:
    Enemy(std::string Name, std::vector<Object>& _rotates, std::vector<Object>& _solids, float X, float Y, int W, int H);

    /// Проверяем нажатия клавиш
    void selectDirection(float targetX, float targetY);

    float calculateDist(float x1, float y1, float x2, float y2);

    /// Проверяем столкновения
    void checkCollisionWithMap(float Dx, float Dy);

    /// Обновляем позицию игрока
    void updatePosition(float time);

    void update(float time, float targetX, float targetY);

    bool isSolid(float _x, float _y);
};


// Красный
class Blinky: public Enemy{
public:
    Blinky(std::string Name, std::vector<Object>& _rotates, std::vector<Object>& _solids, float X, float Y, int W, int H)
        : Enemy(Name, _rotates, _solids, X, Y, W, H )
    {
        //sprite.setColor(Color::Black);
        dx = speed;
    }
};

// Розовый
class Pinky: public Enemy{
public:
    Pinky(std::string Name, std::vector<Object>& _rotates, std::vector<Object>& _solids, float X, float Y, int W, int H)
        : Enemy(Name, _rotates, _solids, X, Y, W, H )
    {

    }
};


// Голубой
class Inky: public Enemy{
public:
    Inky(std::string Name, std::vector<Object>& _rotates, std::vector<Object>& _solids, float X, float Y, int W, int H) :
        Enemy(Name, _rotates, _solids, X, Y, W, H )
    {
        //sprite.setColor(Color::Blue);
    }
};

// Оранжевый
class Clyde: public Enemy{
public:
    Clyde(std::string Name, std::vector<Object>& _rotates, std::vector<Object>& _solids, float X, float Y, int W, int H)
        : Enemy(Name, _rotates, _solids, X, Y, W, H )
    {
        //sprite.setColor(Color::Transparent);
    }
};

#endif // ENEMY_H
