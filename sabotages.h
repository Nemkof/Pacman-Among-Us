#ifndef SABOTAGES_H
#define SABOTAGES_H
#include <SFML/Graphics.hpp>
#include "level.h"
using namespace sf;

class Sabotage{
private:
    enum class Condition{
        notSolved,
        Solved,
        inProcess
    } tasksCondition;
    int w, h;
    Texture texture;
    Sprite sprite;

    float delay = 0; // Задержка между саботажами
    float spriteNumber = 0; // для мигания спрайтов
public:
    Sabotage(const Image& image, const Object& object);

    void update(float time);

    Sprite getSprite();

    void run();
};



#endif // SABOTAGES_H
