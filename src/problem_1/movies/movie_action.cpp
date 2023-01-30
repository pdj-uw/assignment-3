#include "movie_action.h"

int MovieAction::calculate_late_fees(int num_of_days_past_due) {
    /*
     * TODO: homework
     */
}

bool MovieAction::action_movie_mercy_rule_apply() {
    return title.find("pulp fiction") != std::string::npos;
}

bool MovieAction::mercy_rule_apply() {
    return StoreMediaInterface::mercy_rule_apply() && action_movie_mercy_rule_apply();
}