#ifndef ENEMY_H
#define ENEMY_H
#include "MovableEntity.h"
enum class GhostState{ Chase, Scatter, Frightened };
class Enemy: public MovableEntity{
public:
    Direction lastDir;
    std::vector<Object> rotates;
    std::vector<Object> solids; // Вектор объектов карты

    GhostState ghostState = GhostState::Chase;
    float timeGhostState;

    float lastRotateX = 0.0;
    float lastRotateY = 0.0;

    Enemy(const Object& object);

    /// Проверяем нажатия клавиш
    void selectDirection(float targetX, float targetY);

    float calculateDist(float x1, float y1, float x2, float y2);

    void checkCollisionWithMap(float Dx, float Dy);
    void updatePosition(float time);
    void update(float time, float targetX, float targetY);

    FloatRect getRectForRotates();

    bool isSolid(float _x, float _y);

    virtual float getTargetX(float x) = 0;
    virtual float getTargetY(float y) = 0;

    void setRotates(const std::vector<Object>& _rotates) {rotates = _rotates;}
    void setSolids(const std::vector<Object>& _solids) {solids = _solids;}
};

// Красный
class Blinky: public Enemy{
public:
    Blinky(const Object& object)
        : Enemy(object)
    {

    }
    float getTargetX(float x) override {
        return x;
    }
    float getTargetY(float y) override {
        return y;
    }
};

// Розовый
class Pinky: public Enemy{
public:
    Pinky(const Object& object)
        : Enemy(object)
    {

    }
    float getTargetX(float x) override {
        return x + 320;
    }
    float getTargetY(float y) override {
        return y;
    }
};


// Голубой
class Inky: public Enemy{
public:
    Inky(const Object& object) :
        Enemy(object)
    {
        direction = Direction::left;
    }
    float getTargetX(float x) override {
        return x - 320;
    }
    float getTargetY(float y) override {
        return y;
    }
};

// Оранжевый
class Clyde: public Enemy{
public:
    Clyde(const Object& object)
        : Enemy(object)
    {
        direction = Direction::left;
    }
    float getTargetX(float x) override {
        return x;
    }
    float getTargetY(float y) override {
        return y + 320;
    }
};

#endif // ENEMY_H
