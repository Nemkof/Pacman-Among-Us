#ifndef LIVES_H
#define LIVES_H
#include <SFML/Graphics.hpp>
#include "level.h"
#include "Entity.h"

using namespace sf;
class Lives: public Entity{
private:
public:
    Lives(const Object& object);

    void update(int lives);
};
#endif // LIVES_H
