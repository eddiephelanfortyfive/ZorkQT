// Room.h
#ifndef ROOM_H
#define ROOM_H

#include "exit.h"
#include <QString>
#include <vector>
#include "item.h"

#include <string>
class Exit;

class Room {
public:
    Room(int id, const std::string& description);
    int getId() const;
    void addItem(Item* item);
    void removeItem(Item* item);
    const std::string& getDescription() const;
    void addExit(Exit* exit);
    const std::vector<Exit*>& getExits() const;
    const std::vector<Item*>& getItems() const;

private:
    int m_id;
    std::string m_description;
    std::vector<Exit*> m_exits;
    std::vector<Item*> m_items;
};

#endif // ROOM_H
