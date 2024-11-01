#include "enemy.h"
#include <limits>
Enemy::Enemy(const std::vector<Object>& _rotates, const std::vector<Object>& _solids, const Object& object)
    : Entity(object)
{
    solids = _solids;
    sprite.setTextureRect(IntRect(0, 0, w, h));
    sprite.setColor(Color::White);
    sprite.setPosition(x, y);
    speed = 0.1;
    dx = speed;
    dy = 0;
    state = right;
    rotates = _rotates;

    lastRotateX = 0.0;
    lastRotateY = 0.0;
}

/// Логика движения за игроком
void Enemy::selectDirection(float targetX, float targetY){
    Direction nextDir = stay;

    float minDist = std::numeric_limits<float>::max();

    if(!isSolid(x - 32, y) && (state != Direction::right))
    {
        double dist = calculateDist(targetX, targetY, x - 32, y);
        if (dist < minDist){
            nextDir = Direction::left;
            minDist = dist;
        }
    }
    if(!isSolid(x + 32, y) && (state != Direction::left))
    {
        double dist = calculateDist(targetX, targetY, x + 32, y);
        if (dist < minDist){
            nextDir = Direction::right;
            minDist = dist;
        }
    }
    if(!isSolid(x, y - 32) && (state != Direction::down))
    {
        double dist = calculateDist(targetX, targetY, x, y - 32);
        if (dist < minDist){
            nextDir = Direction::up;
            minDist = dist;
        }
    }
    if(!isSolid(x, y + 32) && (state != Direction::up))
    {
        double dist = calculateDist(targetX, targetY, x, y + 32);
        if (dist < minDist){
            nextDir = Direction::down;
        }
    }
    if(nextDir != stay) {
        state = nextDir;
    }
    else{
        if(state == right) {state = left;}
        else if(state == left) {state = right;}
        else if(state == down) {state = up;}
        else if(state == up) {state = down;}
    }

}

bool Enemy::isSolid(float _x, float _y){
    for (size_t i = 0; i < solids.size(); i++)
    {
        if (FloatRect(_x, _y, w, h).intersects(solids[i].rect)) // Если пересекаемся с каким-то тайликом
        {
            return true; // То мы не можем идти в эту сторону
        }
    }
    return false; // Если мы не столкнулись со стеной, то можно идти в эту сторону
}

float Enemy::calculateDist(float x1, float y1, float x2, float y2){
    return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}

/// Проверяем столкновения
void Enemy::checkCollisionWithMap(float Dx, float Dy){
    for (size_t i = 0; i < solids.size(); i++) // Проходимся по всем элементам карты
    {
        if (getRect().intersects(solids[i].rect)) // Если мы пересекаемся с каким-то тайликом
        {
           // То мы должны остановить нашего игрока перед стеной
            if (Dy>0)	{ y = solids[i].rect.top - h;  dy = 0; state = down;}
            if (Dy<0)	{ y = solids[i].rect.top + solids[i].rect.height;   dy = 0; state = up;}
            if (Dx>0)	{ x = solids[i].rect.left - w; dx = 0; state = right;}
            if (Dx<0)	{ x = solids[i].rect.left + solids[i].rect.width; dx = 0; state = left;}
        }
    }
}

void Enemy::updatePosition(float time){
    if(state == right) {dx = speed; dy = 0; state = right;}
    else if(state == left) {dx = -speed; dy = 0; state = left;}
    else if(state == down) {dy = speed; dx = 0; state = down;}
    else if(state == up) {dy = -speed; dx = 0; state = up;}

    x += dx*time;
    checkCollisionWithMap(dx, 0);
    y += dy*time;
    checkCollisionWithMap(0, dy);
    sprite.setPosition(x + w / 2, y + h / 2);
}

void Enemy::update(float time, float playerX, float playerY)
{
    float targetX = getTargetX(playerX);
    float targetY = getTargetY(playerY);

    // Проходимся по всем элементам карты
    for (size_t i = 0; i < rotates.size(); i++)
    {
        // Если мы находимся на перекрестке
        if (getRectForRotates().intersects(rotates[i].rect))
        {
            if(calculateDist(lastRotateX, lastRotateY, rotates[i].rect.left, rotates[i].rect.top) > 96){
                selectDirection(targetX, targetY);
                lastRotateX = rotates[i].rect.left;
                lastRotateY = rotates[i].rect.top;

            }
        }
    }

    //Если мы остановились, значит столкнулись со стеной. Нужно повернуть
    if(dx == 0 && dy == 0)
    {
        selectDirection(targetX, targetY);
        lastRotateX = x;
        lastRotateY = y;
    }

    updatePosition(time);

    sprite.setPosition(x + w / 2, y + h / 2);
    updateSprites(dx, time);

    vov();
}

void Enemy::vov(){
    sprite.setColor(Color(rand(),rand(),rand()));
}
