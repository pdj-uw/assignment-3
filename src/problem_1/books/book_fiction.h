#include "book.h"

#pragma once

class BookFiction : public Book {
private:
    std::string genres;

public:
    BookFiction(const std::string &title,
                const std::string &author,
                const std::string &genre,
                const size_t id) : Book(title, author, id) {
        this->genres = genre;
    }
};