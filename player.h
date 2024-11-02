#ifndef PLAYER_H
#define PLAYER_H
#include "enemy.h"
#include "food.h"
#include "sabotages.h"
class Player : public Entity {
private:
    enum { left, right, up, down, stay } state = stay;
    short lives = 3;
    std::vector<Object> obj; // Вектор объектов карты

    std::vector<Apple>* apples;
    Banana* firstBanana;
    Banana* secondBanana;

    Sabotage* firstSabotage;
    Sabotage* secondSabotage;

    int applesNumber;
    int score = 0;
public:
    Player(const std::vector<Object>& _obj, const Object& object);

    void control();

    /// Проверяем столкновения
    void checkCollisionWithMap (float time, float Dx, float Dy, const std::vector<Enemy*>& entities);
    /// Обновляем позицию игрока
    void updatePosition(float time, const std::vector<Enemy*>& entities);
    void update(float time, const std::vector<Enemy*>& entities);

    int getLives();

    int getScore();
    void checkScore();

    void setApples(std::vector<Apple>* _apples);
    void setFirstBanana(Banana* _firstBanana);
    void setSecondBanana(Banana* _secondBanana);
    void setFirstSabotage(Sabotage* _firstSabotage);
    void setSecondSabotage(Sabotage* _secondSabotage);
};

#endif // PLAYER_H
