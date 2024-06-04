#ifndef ENTITY_H
#define ENTITY_H
#include <QString>

class Entity {
public:
    virtual ~Entity() {}
    virtual const QString getDescription() const = 0;
};

#endif
