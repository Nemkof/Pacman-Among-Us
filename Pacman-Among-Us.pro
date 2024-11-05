TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG += qt
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
SOURCES += \
        TinyXML/tinystr.cpp \
        TinyXML/tinyxml.cpp \
        TinyXML/tinyxmlerror.cpp \
        TinyXML/tinyxmlparser.cpp \
        enemy.cpp \
        main.cpp \
        menuwindow.cpp \
        player.cpp \
        sabotages.cpp \
        sabotagewidget.cpp


LIBS += -LC:\myQT\projects\SFML-2.6.1\lib
LIBS += -LC:\myQT\projects\SFML-2.6.1\bin

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window -lsfml-main
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window -lsfml-main

INCLUDEPATH += C:\myQT\projects\SFML-2.6.1\include
DEPENDPATH += C:\myQT\projects\SFML-2.6.1\include

HEADERS += \
    Entity.h \
    MovableEntity.h \
    TinyXML/tinystr.h \
    TinyXML/tinyxml.h \
    Ventilation.h \
    enemy.h \
    food.h \
    gamemanager.h \
    level.h \
    lives.h \
    menuwindow.h \
    player.h \
    sabotages.h \
    sabotagewidget.h

FORMS += \
    menuwindow.ui \
    sabotagewidget.ui

DISTFILES += \
    images/Blinky.png \
    images/Clyde.png \
    images/Inky.png \
    images/Pinky.png \
    images/Player.png \
    images/Tiny_Chao_Garden_SonicAdv_3_Tile_Sheet.png \
    images/apple.png \
    images/entity.png \
    images/forText.ttf \
    images/hatch.png \
    images/image_for_map.png \
    images/lives.png \
    images/menu/Background.png \
    images/menu/Banner.png \
    images/menu/Exit.png \
    images/menu/Howtoplay.png \
    images/menu/Settings.png \
    images/menu/about.png \
    images/menu/buttons.png \
    images/menu/py.png \
    images/menu/start.png \
    sounds/button1.wav \
    sounds/music.mp3 \
    sounds/music.ogg
