#ifndef EXIT_H
#define EXIT_H
#include "entity.h"
#include <QString>

class Room;

class Exit : public Entity
{
public:
    Exit(const QString& direction, Room* destination, const QString description);
    virtual ~Exit() override;
    virtual const QString getDescription() const override;
    const QString& getDirection() const;
    Room* getDestination() const;

private:
    QString m_direction;
    Room* m_destination;
    QString m_description;
};

#endif
