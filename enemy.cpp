#include "enemy.h"
#include <limits>
Enemy::Enemy(const Object& object, const Object& targetPoint)
    : MovableEntity(object)
{
    sprite.setTextureRect(IntRect(0, 0, w, h));
    sprite.setColor(Color::White);
    sprite.setPosition(x, y);
    speed = 0.15;
    dx = speed;
    dy = 0;
    direction = Direction::right;

    targetPointX = targetPoint.rect.left;
    targetPointY = targetPoint.rect.top;

    lastRotateX = 0.0;
    lastRotateY = 0.0;
}

/// Логика движения за игроком
void Enemy::selectDirection(float targetX, float targetY){
    Direction nextDir = Direction::stay;

    float minDist = std::numeric_limits<float>::max();

    if(!isSolid(x - 32, y) && (direction != Direction::right))
    {
        double dist = calculateDist(targetX, targetY, x - 32, y);
        if (dist < minDist){
            nextDir = Direction::left;
            minDist = dist;
        }
    }
    if(!isSolid(x + 32, y) && (direction != Direction::left))
    {
        double dist = calculateDist(targetX, targetY, x + 32, y);
        if (dist < minDist){
            nextDir = Direction::right;
            minDist = dist;
        }
    }
    if(!isSolid(x, y - 32) && (direction != Direction::down))
    {
        double dist = calculateDist(targetX, targetY, x, y - 32);
        if (dist < minDist){
            nextDir = Direction::up;
            minDist = dist;
        }
    }
    if(!isSolid(x, y + 32) && (direction != Direction::up))
    {
        double dist = calculateDist(targetX, targetY, x, y + 32);
        if (dist < minDist){
            nextDir = Direction::down;
        }
    }
    if(nextDir != Direction::stay) {
        direction = nextDir;
    }
    else{
        if(direction == Direction::right) {direction = Direction::left;}
        else if(direction == Direction::left) {direction = Direction::right;}
        else if(direction == Direction::down) {direction = Direction::up;}
        else if(direction == Direction::up) {direction = Direction::down;}
    }

}

bool Enemy::isSolid(float _x, float _y){
    for (size_t i = 0; i < solids->size(); i++)
    {
        if (FloatRect(_x, _y, w, h).intersects(solids->at(i).rect)) // Если пересекаемся с каким-то тайликом
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
    for (size_t i = 0; i < solids->size(); i++) // Проходимся по всем элементам карты
    {
        if (getRect().intersects(solids->at(i).rect)) // Если мы пересекаемся с каким-то тайликом
        {
           // То мы должны остановить нашего игрока перед стеной
            if (Dy>0)	{ y = solids->at(i).rect.top - h;  dy = 0; direction = Direction::down;}
            if (Dy<0)	{ y = solids->at(i).rect.top + solids->at(i).rect.height;   dy = 0; direction = Direction::up;}
            if (Dx>0)	{ x = solids->at(i).rect.left - w; dx = 0; direction = Direction::right;}
            if (Dx<0)	{ x = solids->at(i).rect.left + solids->at(i).rect.width; dx = 0; direction = Direction::left;}
        }
    }
}

void Enemy::updatePosition(float time){
    if(direction == Direction::right) {dx = speed; dy = 0; direction = Direction::right;}
    else if(direction == Direction::left) {dx = -speed; dy = 0; direction = Direction::left;}
    else if(direction == Direction::down) {dy = speed; dx = 0; direction = Direction::down;}
    else if(direction == Direction::up) {dy = -speed; dx = 0; direction = Direction::up;}

    x += dx*time;
    checkCollisionWithMap(dx, 0);
    y += dy*time;
    checkCollisionWithMap(0, dy);
    sprite.setPosition(x + w / 2, y + h / 2);
}

void Enemy::update(float time, float playerX, float playerY)
{
    timeGhostState += time;
    if(timeGhostState > 10000){
        if(ghostState == GhostState::Chase)
            ghostState = GhostState::Scatter;
        else
            ghostState = GhostState::Chase;
        timeGhostState = 0;
        speed = 0.15;
        sprite.setColor(Color::White);
    }


    float targetX = getTargetX(playerX);
    float targetY = getTargetY(playerY);

    // Проходимся по всем элементам карты
    for (size_t i = 0; i < rotates->size(); i++)
    {
        // Если мы находимся на перекрестке
        if (getRectForRotates().intersects(rotates->at(i).rect))
        {
            if(calculateDist(lastRotateX, lastRotateY, rotates->at(i).rect.left, rotates->at(i).rect.top) > 96){
                selectDirection(targetX, targetY);
                lastRotateX = rotates->at(i).rect.left;
                lastRotateY = rotates->at(i).rect.top;
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

    updateNamePosition();

    if(ghostState == GhostState::Frightened)
    {
        sprite.setColor(Color(rand(), rand(), rand()));
        speed = 0.05;
    }
}
FloatRect Enemy::getRectForRotates(){  // функция получения прямоугольника. координаты объекта, размер (ширина, высота).
    return FloatRect(x, y, w / 2, h / 2); // нужна для проверки столкновений
}


void Enemy::kill(){
    x = startX;
    y = startY;
}

void Enemy::runAway(){
    ghostState = GhostState::Frightened;
    if(direction == Direction::down) direction = Direction::up;
    else if(direction == Direction::left) direction = Direction::right;
    else if(direction == Direction::right) direction = Direction::left;
    else if(direction == Direction::up) direction = Direction::down;

}
