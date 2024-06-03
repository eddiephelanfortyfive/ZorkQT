#ifndef ITEM_H
#define ITEM_H
#include "entity.h"

class Item : public Entity {
public:
    Item(const QString name, const QString description);
    Item(const Item& other);
    virtual ~Item() override; // Override the destructor
    virtual const QString getDescription() const override;

    const QString getName() const;

private:
    QString m_name;
    QString m_description;
};

#endif // ITEM_H
