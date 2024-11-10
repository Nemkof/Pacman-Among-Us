#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H
#include <iostream>

using namespace std;
enum class Controller{
    Letters,
    Arrows
};
class GameSettings{
public:
    static string Nickname;
    static bool Sounds;
    static Controller controller;
};

#endif // GAMESETTINGS_H
