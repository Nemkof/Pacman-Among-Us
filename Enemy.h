#ifndef ENEMY_H
#define ENEMY_H
#include "MovableEntity.h"
enum class GhostState{ Chase, Scatter, Frightened };
class Enemy: public MovableEntity{
public:
    std::vector<Object>* rotates;
    std::vector<Object>* solids; // Вектор объектов карты

    static GhostState ghostState;
    static float timeGhostState;

    float lastRotateX = 0.0;
    float lastRotateY = 0.0;

    float targetPointX = 0.0;
    float targetPointY = 0.0;

    Enemy(const Object& object, const Object& targetPoint);

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

    void setRotates(std::vector<Object>* _rotates) {rotates = _rotates;}
    void setSolids(std::vector<Object>* _solids) {solids = _solids;}

    void death();
    void runAway();
};

// Красный
class Blinky: public Enemy{
public:
    Blinky(const Object& object, const Object& targetPoint)
        : Enemy(object, targetPoint)
    {
        name = "Blinky";
        textName.setString(name);
    }
    float getTargetX(float x) override {
        if(ghostState == GhostState::Chase)
            return x;
        else return targetPointX;
    }
    float getTargetY(float y) override {
        if(ghostState == GhostState::Chase)
            return y;
        else return targetPointY;
    }
};

// Розовый
class Pinky: public Enemy{
public:
    Pinky(const Object& object, const Object& targetPoint)
        : Enemy(object, targetPoint)
    {
        name = "Pinky";
        textName.setString(name);
    }
    float getTargetX(float x) override {
        if(ghostState == GhostState::Chase)
            return x + 320;
        else return targetPointX;
    }
    float getTargetY(float y) override {
        if(ghostState == GhostState::Chase)
            return y;
        else return targetPointY;
    }
};


// Голубой
class Inky: public Enemy{
public:
    Inky(const Object& object, const Object& targetPoint) :
        Enemy(object, targetPoint)
    {
        name = "Inky";
        textName.setString(name);
    }
    float getTargetX(float x) override {
        if(ghostState == GhostState::Chase)
            return x - 320;
        else return targetPointX;
    }
    float getTargetY(float y) override {
        if(ghostState == GhostState::Chase)
            return y;
        else return targetPointY;
    }
};

// Оранжевый
class Clyde: public Enemy{
public:
    Clyde(const Object& object, const Object& targetPoint)
        : Enemy(object, targetPoint)
    {
        name = "Clyde";
        textName.setString(name);
    }
    float getTargetX(float x) override {
        if(ghostState == GhostState::Chase)
            return x;
        else return targetPointX;
    }
    float getTargetY(float y) override {
        if(ghostState == GhostState::Chase)
            return y + 320;
        else return targetPointY;
    }
};

#endif // ENEMY_H
