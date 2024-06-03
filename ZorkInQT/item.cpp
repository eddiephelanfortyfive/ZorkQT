#include "item.h"

Item::Item(const QString name, const QString description)
    : m_name(name), m_description(description) {}

Item::Item(const Item& other)
    : m_name(other.m_name), m_description(other.m_description) {}

Item::~Item(){}

const QString Item::getDescription() const {
    return m_description;
}

const QString Item::getName() const {
    return m_name;
}
