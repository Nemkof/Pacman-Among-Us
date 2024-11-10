#ifndef SABOTAGES_H
#define SABOTAGES_H
#include "Entity.h"
using namespace sf;

class Sabotage: public Entity{
private:



    float spriteNumber = 0; // для мигания спрайтов
public:
    enum class TaskCondition{
        notSolved,
        Solved,
        inProcess
    } tasksCondition;
    float delay = 0; // Задержка между саботажами

    Sabotage(const Object& object);

    void update(float time);

    bool run();
};



#endif // SABOTAGES_H
