/*
 * DO NOT MAKE ANY CHANGES
 */

#include "book.h"

#pragma once

class BookRomance : public Book {
private:
    std::string genres;
    const int late_fee_per_day = 4;

public:
    BookRomance(const std::string &title,
                const std::string &author,
                const std::string &genre,
                const size_t id) : Book(title, author, id) {
        this->genres = genre;
        set_late_fee_per_day_in_dollar(late_fee_per_day);
    }

    bool mercy_rule_apply() override;
};