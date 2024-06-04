// WorldBuilder.h
#ifndef WORLDBUILDER_H
#define WORLDBUILDER_H
#include "player.h"
#include "room.h"
class MainWindow;
class WorldBuilder
{
public:
    WorldBuilder();
    ~WorldBuilder();
    void createRooms();
    void buildWorld();
    Player* getPlayer() const;
    int getNumberOfRooms();

private:
    std::vector<Room*> m_rooms;
    Player* m_player;

    friend class MainWindow;
};

#endif
