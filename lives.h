#ifndef LIVES_H
#define LIVES_H
#include <SFML/Graphics.hpp>
#include "level.h"

using namespace sf;
class Lives{
private:
    int w, h;
    Texture texture;
    Sprite sprite;
public:
    Lives(const Object& object);

    void update(int lives);

    Sprite getSprite();
};
#endif // LIVES_H
