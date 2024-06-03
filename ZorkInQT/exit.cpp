#include "exit.h"
#include "room.h"

Exit::Exit(const QString& direction, Room* destination, const QString description)
    : m_direction(direction), m_destination(destination), m_description(description)
{
}
Exit::~Exit(){}

const QString& Exit::getDirection() const
{
    return m_direction;
}

Room* Exit::getDestination() const
{
    return m_destination;
}

const QString Exit::getDescription() const {
    return m_description;
}
