#include "SceneLoader.h"
SceneLoader::SceneLoader(Level& lvl){
    std::vector<Object> obj = lvl.GetAllObjects(); // Получаем вектор всех объектов карты
    for(auto it: obj){
        if (it.name == "rotate") rotates.push_back(it);
        else if(it.name == "solid") {solidsPlayer.push_back(it); solidsEnemy.push_back(it);}
        else if(it.name == "fakesolid1") solidsEnemy.push_back(it);
        else if(it.name == "fakesolid2") solidsEnemy.push_back(it);
        else if(it.name == "apple") appleObjects.push_back(it);
        else if(it.name == "energy") energyObjects.push_back(it);
        else if(it.name == "firstBanana") firstBananaObject = it;
        else if(it.name == "secondBanana") secondBananaObject = it;
        else if(it.name == "player") playerObject = it;
        else if(it.name == "Blinky") blinkyObject = it;
        else if(it.name == "Pinky") pinkyObject = it;
        else if(it.name == "Inky") inkyObject = it;
        else if(it.name == "Clyde") clydeObject = it;
        else if(it.name == "BlinkyTarget") blinkyTargetObject = it;
        else if(it.name == "PinkyTarget") pinkyTargetObject = it;
        else if(it.name == "InkyTarget") inkyTargetObject = it;
        else if(it.name == "ClydeTarget") clydeTargetObject = it;
        else if(it.name == "sabotageFirst") firstSabotageObject = it;
        else if(it.name == "sabotageSecond") secondSabotageObject = it;
        else if(it.name == "lives") livesObject = it;
        else if(it.name == "score") scoreObject = it;
        else if(it.name == "time") timeObject = it;
        else if(it.name == "state") stateObject = it;
        else if(it.name == "tasks") tasksObject = it;
        else if(it.name == "firstVentilation") firstVentilationObject = it;
        else if(it.name == "secondVentilation") secondVentilationObject = it;
    }
}

