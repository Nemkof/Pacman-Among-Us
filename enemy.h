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
    Enemy(std::vector<Object>& _rotates, std::vector<Object>& _solids, Object object);

    /// Проверяем нажатия клавиш
    void selectDirection(float targetX, float targetY);

    float calculateDist(float x1, float y1, float x2, float y2);

    /// Проверяем столкновения
    void checkCollisionWithMap(float Dx, float Dy);

    /// Обновляем позицию игрока
    void updatePosition(float time);

    void update(float time, float targetX, float targetY);

    bool isSolid(float _x, float _y);

    virtual float getTargetX(float x) = 0;
    virtual float getTargetY(float y) = 0;
};


// Красный
class Blinky: public Enemy{
public:
    Blinky(std::vector<Object>& _rotates, std::vector<Object>& _solids, Object object)
        : Enemy(_rotates, _solids, object)
    {

    }
    float getTargetX(float x) override {return x;}
    float getTargetY(float y) override {return y;}
};

// Розовый
class Pinky: public Enemy{
public:
    Pinky(std::vector<Object>& _rotates, std::vector<Object>& _solids, Object object)
        : Enemy(_rotates, _solids, object)
    {

    }
    float getTargetX(float x) override {return x + 200;}
    float getTargetY(float y) override {return y;}
};


// Голубой
class Inky: public Enemy{
public:
    Inky(std::vector<Object>& _rotates, std::vector<Object>& _solids, Object object) :
        Enemy(_rotates, _solids, object)
    {
    }
    float getTargetX(float x) override {return x - 200;}
    float getTargetY(float y) override {return y;}
};

// Оранжевый
class Clyde: public Enemy{
public:
    Clyde(std::vector<Object>& _rotates, std::vector<Object>& _solids, Object object)
        : Enemy(_rotates, _solids, object)
    {
    }
    float getTargetX(float x) override {return x;}
    float getTargetY(float y) override {return y + 200;}
};

#endif // ENEMY_H
