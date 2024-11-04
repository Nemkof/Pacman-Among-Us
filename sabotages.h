#ifndef SABOTAGES_H
#define SABOTAGES_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Sabotage{
private:
    enum class Condition{
        notSolved,
        Solved,
        inProcess
    } tasksCondition;
    int w, h, x, y;
    Texture texture;
    Sprite sprite;

    float delay = 0; // Задержка между саботажами
    float spriteNumber = 0; // для мигания спрайтов
public:
    Sabotage(const Image& image, const float& _x, const float& _y);

    void update(float time);

    Sprite getSprite();
    FloatRect getRect();
    void run();
};



#endif // SABOTAGES_H
