#ifndef SABOTAGES_H
#define SABOTAGES_H
#include "Entity.h"
using namespace sf;

class Sabotage: public Entity{
private:
    enum class Condition{
        notSolved,
        Solved,
        inProcess
    } tasksCondition;

    float delay = 0; // Задержка между саботажами
    float spriteNumber = 0; // для мигания спрайтов
public:
    Sabotage(const Object& object);

    void update(float time);

    void run();
};



#endif // SABOTAGES_H
