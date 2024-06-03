// Room.cpp
#include "room.h"
#include "exit.h"
#include "qdebug.h"
#include <QString>

Room::Room(int id, const std::string& description)
    : m_id(id), m_description(description) {}

int Room::getId() const {
    return m_id;
}

const std::string& Room::getDescription() const {
    return m_description;
}

void Room::addExit(Exit* exit) {
    m_exits.push_back(exit);
}

const std::vector<Exit*>& Room::getExits() const {
    return m_exits;
}
void Room::addItem(Item* item) {
    m_items.push_back(item);
}

void Room::removeItem(Item* item) {
    auto it = std::find(m_items.begin(), m_items.end(), item);
    if (it != m_items.end()) {
        m_items.erase(it);
        qDebug() << "Removed item" << item->getName() << "from room" << m_id;
    }
}


const std::vector<Item*>& Room::getItems() const {
    qDebug() << "Getting items for room" << m_id;
    return m_items;
}

