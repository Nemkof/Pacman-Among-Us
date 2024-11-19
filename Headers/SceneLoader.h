#ifndef SCENELOADER_H
#define SCENELOADER_H
#include "level.h"
class SceneLoader{
public:
    std::vector<Object> rotates; // Получаем вектор из всех тайлов-поворотов
    std::vector<Object> solidsEnemy; // Получаем вектор из всех тайлов-стен
    std::vector<Object> solidsPlayer; // Получаем вектор из всех тайлов-стен
    std::vector<Object> appleObjects; // Получаем вектор из всех тайлов-яблочек
    std::vector<Object> energyObjects; // Получаем вектор из всех тайлов-энерджайзеров
    Object firstBananaObject; // Получаем первый банан
    Object secondBananaObject; // Получаем второй банан
    Object playerObject; // Получаем тайл игрока
    Object blinkyObject; // Получаем тайл блинки
    Object pinkyObject; // Получаем тайл пинки
    Object inkyObject; // Получаем тайл инки
    Object clydeObject; // Получаем тайл клайда
    Object blinkyTargetObject; // Получаем тайл блинки
    Object pinkyTargetObject; // Получаем тайл пинки
    Object inkyTargetObject; // Получаем тайл инки
    Object clydeTargetObject; // Получаем тайл клайда
    Object firstSabotageObject; // Получаем тайл первого саботажа
    Object secondSabotageObject; // Получаем тайл второго саботажа
    Object livesObject; // Получаем тайл сердечек
    Object scoreObject; // Получаем тайл очков
    Object stateObject; // Получаем тайл очков
    Object timeObject; // Получаем тайл очков
    Object tasksObject; // Получаем тайл очков
    Object levelNumObject; // Получаем тайл очков
    Object firstVentilationObject; // Получаем тайл первой вентиляции
    Object secondVentilationObject; // Получаем тайл второй вентиляции

    SceneLoader(Level& lvl);
};

#endif // SCENELOADER_H
