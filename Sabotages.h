#ifndef SABOTAGES_H
#define SABOTAGES_H
#include "Entity.h"
using namespace sf;

class Sabotage: public Entity{
private:
    float spriteNumber = 0; // для мигания спрайтов
public:
    static short solvedTasks;
    float delay = 0; // Задержка между саботажами

    Sabotage(const Object& object);

    void update(float time);

    bool run();
    static short getSolvedTasks() { return solvedTasks; }
    static void setSolvedTasks() { solvedTasks++; }
};


#endif // SABOTAGES_H
