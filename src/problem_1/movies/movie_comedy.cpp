#include "movie_comedy.h"

int MovieComedy::calculate_late_fees(int num_of_days_past_due)
{
	if (num_of_days_past_due == 0)
		return 0;
	else if (num_of_days_past_due <= 5)
		return late_fee_per_day;
	else if (num_of_days_past_due <= 10)
		return late_fee_per_day * 2;
	else
		return late_fee_per_day * num_of_days_past_due;
}
