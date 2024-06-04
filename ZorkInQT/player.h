#ifndef PLAYER_H
#define PLAYER_H

#include "room.h"
#include "item.h"
#include "inventory.h"
#include <vector>
#include <QObject>

class Player : public QObject
{
    Q_OBJECT

public:
    Player(Room* startingRoom);
    ~Player();

    void moveTo(Room &room);
    Room* getCurrentRoom() const;
    void addItemToInventory(Item* item);
    void removeItemFromInventory(Item* item);
    const std::vector<Item*>& getInventory() const;

signals:
    void moved();

private:
    Room* m_currentRoom;
    Inventory<Item> m_inventory;
};

#endif

