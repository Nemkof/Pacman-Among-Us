#include "food.h"


Food::Food(Sprite _sprite, int _x, int _y): sprite(_sprite), x(_x), y(_y){
    sprite.setTextureRect(IntRect(0,0,32,32));
    sprite.setPosition(x,y);
    status = false;
}


void Food::Dead(){
    status = true;
}


bool Food::isDead()
{
    return status;
}


Sprite Food::getSprite(){
    return sprite;
}
