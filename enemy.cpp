#include "enemy.h"
#include <limits>
Enemy::Enemy(std::vector<Object>& _rotates, std::vector<Object>& _solids, Object object)
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
}

/// Логика движения за игроком
void Enemy::selectDirection(float targetX, float targetY){
    Direction nextDir = stay;

    float minDist = std::numeric_limits<float>::max();

    if(!isSolid(x - 5, y) && (state != Direction::right))
    {
        double dist = calculateDist(targetX, targetY, x - 5, y);
        if (dist < minDist){
            nextDir = Direction::left;
            minDist = dist;
        }
    }
    if(!isSolid(x + 5, y) && (state != Direction::left))
    {
        double dist = calculateDist(targetX, targetY, x + 5, y);
        if (dist < minDist){
            nextDir = Direction::right;
            minDist = dist;
        }
    }
    if(!isSolid(x, y - 5) && (state != Direction::down))
    {
        double dist = calculateDist(targetX, targetY, x, y - 5);
        if (dist < minDist){
            nextDir = Direction::up;
            minDist = dist;
        }
    }
    if(!isSolid(x, y + 5) && (state != Direction::up))
    {
        double dist = calculateDist(targetX, targetY, x, y + 5);
        if (dist < minDist){
            nextDir = Direction::down;
        }
    }
    if(nextDir != stay) {
        state = nextDir;
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
    timeRotates += time;

    float targetX = getTargetX(playerX);
    float targetY = getTargetY(playerY);

    // Проходимся по всем элементам карты
    for (size_t i = 0; i < rotates.size(); i++)
    {
        // Если мы находимся на перекрестке
        if (getRectForRotates().intersects(rotates[i].rect)
            && timeRotates > 1000)
        {
            selectDirection(targetX, targetY);
            timeRotates = 0;
        }
    }

    //Если мы остановились, значит столкнулись со стеной. Нужно повернуть
    if(dx == 0 && dy == 0
        && timeRotates > 1000)
    {
        selectDirection(targetX, targetY);
        timeRotates = 0;;
    }

    updatePosition(time);

    sprite.setPosition(x + w / 2, y + h / 2);
    updateSprites(dx, time);
}
