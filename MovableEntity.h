#ifndef MOVABLEENTITY_H
#define MOVABLEENTITY_H
#include "Entity.h"

enum class Direction { left, right, up, down, stay };
class MovableEntity: public Entity{
public:
    float dx = 0, dy = 0, speed = 0, startX = 0, startY = 0;
    Direction direction = Direction::stay;
    string name;
    Font font;
    Text textName;

    float player_sprites = 0; // Переменная для переключения спрайтов игрока

    MovableEntity(const Object& object, string name = ""): Entity(object, name)
    {
        startX = x; startY = y;

        w = texture.getSize().x / 13;
        h = texture.getSize().y;

        sprite.setOrigin(w / 2, h / 2);    // Создаём имя главного героя
        sprite.setTextureRect(IntRect(0, 0, w, h));

        font.loadFromFile("../../images/forText.ttf");
        textName.setFont(font);
        textName.setCharacterSize(25);
        textName.setStyle(Text::Bold);
        textName.setFillColor(Color::White);
    }

    void updateSprites(float Dx, float time)
    {
        if(Dx < 0) // Идём влево
        {
            player_sprites += 0.02 * time;
            if(player_sprites > 12) player_sprites -= 13;
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

    void updateNamePosition(){
        textName.setPosition(x + 10, y - 20);
    }
};



#endif // MOVABLEENTITY_H
