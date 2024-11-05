#ifndef VENTILATION_H
#define VENTILATION_H
#include "entity.h"
class Ventilation: public Entity
{
public:
    Ventilation(const Object& object): Entity(object, "ventilation"){
        w /= 3;
        sprite.setTextureRect(IntRect(0,0,w,h));
    }

    void updateSprites();
};

#endif // VENTILATION_H
