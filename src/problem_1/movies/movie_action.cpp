#include "movie_action.h"

int MovieAction::calculate_late_fees(int num_of_days_past_due)
{
	int x;

	if (mercy_rule_apply())
		return 0;

	x = num_of_days_past_due * late_fee_per_day;
	return (num_of_days_past_due >= 5) ? 2 * x : x;
}

bool MovieAction::action_movie_mercy_rule_apply() {
    return title.find("pulp fiction") != std::string::npos;
}

bool MovieAction::mercy_rule_apply() {
    return StoreMediaInterface::mercy_rule_apply() && action_movie_mercy_rule_apply();
}
