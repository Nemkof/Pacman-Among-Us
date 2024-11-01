#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"
class Enemy: public Entity{
private:
    Direction lastDir;
    std::vector<Object> rotates;
    std::vector<Object> solids; // Вектор объектов карты
    enum { Chase, Scatter, Frightened } condition;
    float timeRotates;

    float lastRotateX = 0.0;
    float lastRotateY = 0.0;
public:
    Enemy(const std::vector<Object>& _rotates, const std::vector<Object>& _solids, const Object& object);

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

    void vov();
};


// Красный
class Blinky: public Enemy{
public:
    Blinky(const std::vector<Object>& _rotates, const std::vector<Object>& _solids, const Object& object)
        : Enemy(_rotates, _solids, object)
    {

    }
    float getTargetX(float x) override {return x;}
    float getTargetY(float y) override {return y;}
};

// Розовый
class Pinky: public Enemy{
public:
    Pinky(const std::vector<Object>& _rotates, const std::vector<Object>& _solids, const Object& object)
        : Enemy(_rotates, _solids, object)
    {

    }
    float getTargetX(float x) override {return x + 400;}
    float getTargetY(float y) override {return y;}
};


// Голубой
class Inky: public Enemy{
public:
    Inky(const std::vector<Object>& _rotates, const std::vector<Object>& _solids, const Object& object) :
        Enemy(_rotates, _solids, object)
    {
        state = left;
    }
    float getTargetX(float x) override {return x - 400;}
    float getTargetY(float y) override {return y;}
};

// Оранжевый
class Clyde: public Enemy{
public:
    Clyde(const std::vector<Object>& _rotates, const std::vector<Object>& _solids, const Object& object)
        : Enemy(_rotates, _solids, object)
    {
        state = left;
    }
    float getTargetX(float x) override {return x;}
    float getTargetY(float y) override {return y + 400;}
};

#endif // ENEMY_H
