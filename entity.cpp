#include "entity.h"

Entity::Entity(Object object)
    :x(object.rect.left), y(object.rect.top)
{
    startX = x; startY = y;
    speed = 0; dx = 0; dy = 0;
    name = object.name;
    texture.loadFromFile("../../images/" + name + ".png");
    // w = texture.getSize().x / 12;
    // h = texture.getSize().y;

    sprite.setTexture(texture);
    sprite.setOrigin(w / 2, h / 2);    // Создаём имя главного героя
}

/// Обновляем спрайты игрока
void Entity::updateSprites(float Dx, float time)
{
    // < 0 - идем влево
    // >= 0 - иначе
    if(Dx < 0) // Идём влево
    {
        player_sprites += 0.02 * time;
        if(player_sprites > 12) player_sprites -= 12;
        sprite.setTextureRect(IntRect(w * (int)player_sprites, 0, w, h));
        sprite.setScale(-1,1);
        return;
    }
    else// Идём вправо, вверх, вниз
    {
        player_sprites += 0.02 * time;
        if(player_sprites > 11) player_sprites -= 12;
        sprite.setTextureRect(IntRect(w * (int)player_sprites, 0, w, h));
        sprite.setScale(1,1);
        return;
    }
}


FloatRect Entity::getRect(){  // функция получения прямоугольника. координаты объекта, размер (ширина, высота).
    return FloatRect(x, y, w, h); // нужна для проверки столкновений
}


float Entity::getX() {return x;}


float Entity::getY() {return y;}


Sprite Entity::getSprite() {return sprite;}

std::string Entity::getDirection(){
    if(state == left) return "left";
    if(state == right) return "right";
    if(state == up) return "up";
    if(state == down) return "down";
    return "stay";
}
