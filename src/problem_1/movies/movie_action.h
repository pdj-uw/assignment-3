/*
 * DO NOT MAKE ANY CHANGES
 */

#include "movie.h"

#pragma once

class MovieAction : public Movie {
private:
    const int late_fee_per_day = 5;

public:
    MovieAction(const std::string &title, const std::string &rating, const size_t id) : Movie(title, rating, id) {
        set_late_fee_per_day_in_dollar(late_fee_per_day);
    }

    MovieAction(const MovieAction &other_movie_action, const size_t id) : Movie(other_movie_action, id) {
        set_late_fee_per_day_in_dollar(late_fee_per_day);
    }

    int calculate_late_fees(int) override;

    bool mercy_rule_apply() override;

    bool action_movie_mercy_rule_apply();
};