#ifndef LIVES_H
#define LIVES_H
#include <SFML/Graphics.hpp>
using namespace sf;
class Lives{
private:
    int w, h;
    Texture texture;
    Sprite sprite;
public:
    Lives(Image& image, int w, int h, int posX, int posY);

    void update(int lives);

    Sprite getSprite();
};
#endif // LIVES_H
