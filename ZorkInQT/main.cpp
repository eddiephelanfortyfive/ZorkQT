#include <QApplication>
#include "mainwindow.h"
#include "worldBuilder.h"
#include "globals.h"
int playerMoves = 0;
int main(int argc, char *argv[])
{
     QApplication a(argc, argv);
    WorldBuilder builder;
     builder.buildWorld();
    MainWindow mainWindow(builder.getPlayer());
    mainWindow.show();
    return a.exec();
}

