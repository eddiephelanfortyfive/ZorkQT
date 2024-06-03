#include "player.h"

Player::Player(Room* startingRoom)
    : m_currentRoom(startingRoom)
{
}

Player::~Player()
{
}

void Player::moveTo(Room& room)
{
    m_currentRoom = &room;
    emit moved();
}

Room* Player::getCurrentRoom() const
{
    return m_currentRoom;
}

void Player::addItemToInventory(Item* item) {
    m_inventory.addItem(item);
}

void Player::removeItemFromInventory(Item* item) {
    m_inventory.removeItem(item);
}

const std::vector<Item*>& Player::getInventory() const {
    return m_inventory.getItems();
}
