#ifndef SABOTAGES_H
#define SABOTAGES_H
#include <SFML/Graphics.hpp>
#include "level.h"
using namespace sf;
#include "map"
#include "string"
const std::map<std::string, int> questions = {
    {"Чему равна функция Эйлера от 2?", 1},
    {"Чему равна функция Эйлера от 3?", 2},
    {"Чему равна функция Эйлера от 4?", 2},
    {"Чему равна функция Эйлера от 5?", 4},
    {"Чему равна функция Эйлера от 6?", 2},
    {"Чему равна функция Эйлера от 7?", 6},
    {"Чему равна функция Эйлера от 8?", 4},
    {"Чему равна функция Эйлера от 9?", 6},
    {"Чему равна функция Эйлера от 10?", 4},
    };

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

    float spriteNumber = 0; // для мигания спрайтов
public:
    Sabotage(const Image& image, const Object& object);

    void update(float time);

    Sprite getSprite();

    void run();
};



#endif // SABOTAGES_H
