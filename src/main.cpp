#include <cstdio>
#include "problem_2/linked_list.h"
#include "problem_1/books/book_fiction.h"
#include "problem_1/books/book_romance.h"
#include "problem_1/inventory_manager.h"

/*
 * This file is run through memory check.
 * However, any changes in this file will be ignored for grading, EXCEPT its memory leak
 * Meaning, if there's memory leak from this file, there will be points penalty
 */


void problem_2();

void problem_1_static_vs_singleton();

void problem_1_book_fiction();

int main(int argc, char **argv) {
    problem_1_static_vs_singleton();
    problem_1_book_fiction();
    problem_2();
}

void problem_1_book_fiction() {
    auto id = InventoryManager::manager().get_new_id();
    BookFiction fiction("sunrise", "mike", "novel", id);
    printf("book fiction (%zu) late fee is %d\n", fiction.get_inventory_id(), fiction.get_late_fee_per_day_in_dollar());

    id = InventoryManager::manager().get_new_id();
    BookRomance romance("sunset", "tom", "story", id);
    printf("book fiction (%zu) late fee is %d\n", romance.get_inventory_id(), romance.get_late_fee_per_day_in_dollar());
}

void problem_2() {
    LinkedList<int> list;
    list.push_back(99);
    printf("%d\n", list[0]);
}

void problem_1_static_vs_singleton() {
    auto id1 = nsm::get_new_id();
    auto id2 = nsm::get_new_id();
    printf("%lu %lu\n", id1, id2);

    for (int i = 0; i < 5; i++) {
        auto id = InventoryManager::manager().get_new_id();
        printf("inventory id = %zu\n", id);
    }
}