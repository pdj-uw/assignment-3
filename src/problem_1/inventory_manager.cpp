/*
 * DO NOT TOUCH THIS FILE
 */

#include "inventory_manager.h"

// needs the following initialization or will get "undefined reference" error
// put here instead of in .h to avoid "duplicate symbol" linking error
size_t nsm::inventory_id = 0;

InventoryManager &InventoryManager::manager() {
    static InventoryManager instance;
    return instance;
}

size_t InventoryManager::get_new_id() {
    return inventory_id++;
}