#ifndef ITEM_H
#define ITEM_H
#include "entity.h"
#include "name.h"


class Item : public Entity, Name {
public:
    Item(const QString name, const QString description);
    Item(const Item& other);
    virtual ~Item() override; // Override the destructor
    virtual const QString getDescription() const override;
    virtual const QString getName() const override;

private:
    QString m_name;
    QString m_description;
};

#endif
