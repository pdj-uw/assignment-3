/*
 * DO NOT MAKE ANY CHANGES
 */

#include "movie.h"

#pragma once

class MovieComedy : public Movie {
private:
    const int late_fee_per_day = 3;
public:
    MovieComedy(const std::string &title, const std::string &rating, const size_t id) : Movie(title, rating, id) {
        set_late_fee_per_day_in_dollar(late_fee_per_day);
    }

    MovieComedy(const MovieComedy &other_movie_action, const size_t id) : Movie(other_movie_action, id) {
        set_late_fee_per_day_in_dollar(late_fee_per_day);
    }

    int calculate_late_fees(int) override;
};