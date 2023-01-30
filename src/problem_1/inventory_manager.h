/*
 * DO NOT TOUCH THIS FILE
 */

#pragma once

#include <cstdio>

/*
 * another way to achieve a "singleton" behavior
 * how does this compare to a singleton class?
 */
class nsm {
public:
    static size_t inventory_id;

    static size_t get_new_id() {
        return ++inventory_id;
    }
};

// singleton pattern
class InventoryManager {
private:
    size_t inventory_id;

    InventoryManager() {
        inventory_id = 0;
    }

public:
    static InventoryManager &manager();

    size_t get_new_id();

    InventoryManager(InventoryManager const &) = delete;

    void operator=(InventoryManager const &) = delete;
};