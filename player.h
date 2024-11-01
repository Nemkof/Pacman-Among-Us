#ifndef PLAYER_H
#define PLAYER_H
#include "enemy.h"
#include "food.h"
class Player : public Entity {
private:
    enum { left, right, up, down, stay } state;
    short lives = 3;

    std::vector<Apple>* apples;
    Banana* firstBanana;
    Banana* secondBanana;

    int applesNumber;
    int score;
public:/*
    onst std::vector<Object>& _obj, const Object& object, std::vector<Apple> *const _apples,
        Banana *const _firstBanana, Banana *const _secondBanana*/
    Player(const std::vector<Object>& _obj, const Object& object, std::vector<Apple>* _apples,
        Banana* _firstBanana, Banana* _secondBanana);

    void control();

    /// Проверяем столкновения
    void checkCollisionWithMap (float time, float Dx, float Dy, const std::vector<Enemy*>& entities);

    /// Обновляем позицию игрока
    void updatePosition(float time, const std::vector<Enemy*>& entities);

    void update(float time, const std::vector<Enemy*>& entities);

    int isLive();

    int getScore();

    void checkScore();
};

#endif // PLAYER_H
