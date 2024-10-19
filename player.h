#ifndef PLAYER_H
#define PLAYER_H
#include "enemy.h"
#include "food.h"
class Player : public Entity {
private:
    enum { left, right, up, down, stay } state;
    short lives = 3;
    std::vector<Food>* apples;
    int score;
public:
    Player(std::vector<Object>& _obj, Object object, std::vector<Food> *_apples);

    void control();

    /// Проверяем столкновения
    void checkCollisionWithMap (float time, float Dx, float Dy, std::vector<Enemy*> entities);

    /// Обновляем позицию игрока
    void updatePosition(float time, std::vector<Enemy*> entities);

    void update(float time, std::vector<Enemy*> entities);

    int getScore();

    int isLive();

};

#endif // PLAYER_H
