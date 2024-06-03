#ifndef INVENTORY_H
#define INVENTORY_H

#include <algorithm>
#include <vector>

template<typename T>
class Inventory {
private:
    std::vector<T*> items;

public:
    void addItem(T* item) {
        items.push_back(item);
    }

    void removeItem(T* item) {
        auto it = std::find(items.begin(), items.end(), item);
        if (it != items.end()) {
            items.erase(it);
        }
    }

    const std::vector<T*>& getItems() const {
        return items;
    }
};

#endif // INVENTORY_H
