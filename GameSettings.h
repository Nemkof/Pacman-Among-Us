#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H
#include <iostream>

using namespace std;
class GameSettings{
public:
    static string Nickname;
    static int SoundsVolume;
    static enum class Controller{
        Letters,
        Arrows
    } controller;
};

#endif // GAMESETTINGS_H
