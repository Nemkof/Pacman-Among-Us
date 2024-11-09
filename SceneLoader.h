#ifndef SCENELOADER_H
#define SCENELOADER_H
#include "Lives.h"
#include "Player.h"
#include "Sabotages.h"
#include "Ventilation.h"
class SceneLoader{

public:
    std::vector<Object> enemySolids;
    std::vector<Object> playerSolids;

    Sabotage* firstSabotage;
    Sabotage* secondSabotage;

    vector<Apple*> apples;
    vector<Energy*> energies;

    Banana* firstBanana;
    Banana* secondBanana;

    Ventilation* firstVentilation;
    Ventilation* secondVentilation;

    Lives* lives;

    Player* player;
    vector<Enemy*> enemies;

    Font font;
    Text* textScore;
    Text* textTime;

    SceneLoader(Level& lvl);

    ~SceneLoader();


};

#endif // SCENELOADER_H
