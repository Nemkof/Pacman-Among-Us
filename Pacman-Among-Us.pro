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
        src/AboutGameWindow.cpp \
        src/Enemy.cpp \
        src/GameManager.cpp \
        src/HistoryWindow.cpp \
        src/MenuWindow.cpp \
        src/Player.cpp \
        src/SabotageWidget.cpp \
        src/Sabotages.cpp \
        src/SceneLoader.cpp \
        src/SettingsWidget.cpp \
        src/main.cpp


LIBS += -LC:\myQT\projects\SFML-2.6.1\lib
LIBS += -LC:\myQT\projects\SFML-2.6.1\bin

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window -lsfml-main
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window -lsfml-main

INCLUDEPATH += C:\myQT\projects\SFML-2.6.1\include
DEPENDPATH += C:\myQT\projects\SFML-2.6.1\include

HEADERS += \
    Headers/AboutGameWindow.h \
    Headers/Enemy.h \
    Headers/Entity.h \
    Headers/Food.h \
    Headers/Game.h \
    Headers/GameManager.h \
    Headers/GameSettings.h \
    Headers/HistoryWindow.h \
    Headers/Lives.h \
    Headers/MenuWindow.h \
    Headers/MovableEntity.h \
    Headers/Player.h \
    Headers/SabotageWidget.h \
    Headers/Sabotages.h \
    Headers/SceneLoader.h \
    Headers/SettingsWidget.h \
    Headers/Ventilation.h \
    Headers/level.h \
    Headers/ui_AboutGameWindow.h \
    Headers/ui_aboutgamewidget.h \
    Headers/ui_historywindow.h \
    Headers/ui_menuwindow.h \
    Headers/ui_sabotagewidget.h \
    Headers/ui_settings.h \
    Headers/ui_settingsWidget.h \
    TinyXML/tinystr.h \
    TinyXML/tinyxml.h \

FORMS += \
    Forms/AboutGameWindow.ui \
    Forms/HistoryWindow.ui \
    Forms/MenuWindow.ui \
    Forms/SabotageWidget.ui \
    Forms/SettingsWidget.ui \

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
