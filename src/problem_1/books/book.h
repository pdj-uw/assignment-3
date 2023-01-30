/*
 * DO NOT TOUCH THIS FILE
 */

#pragma once

#include <string>
#include "../store_media_interface.h"

class Book : public StoreMediaInterface {
protected:
    std::string title;
    std::string author;

public:
    Book(const std::string &title, const std::string &author, const size_t id) : title(title), author(author) {
        inventory_id = id;
    }

    Book(const Book &other_book) = delete;

    Book(const Book &other_book, size_t id) {
        inventory_id = id;
        this->title = other_book.title;
        this->author = other_book.author;
    }

    virtual ~Book() {}
};