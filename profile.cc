#include "profile.h"

// NOTE - This is a very rough draft, and not a finished product. These are just some of the calculations I will be using
const double Profile::GetTime(ProfilePoint current, ProfilePoint goal, bool use_max_velocity) {
	// Variables
	double a;
	double t_one;

	double d_one;
	double d_two;

	double time_tl;
	double time_r;

	double t_total;

	// Operations for Part Two
	t_one - (v_max-v_initial) / a;

	d_one = 0.5 * v_max * t_one;
	d_two = goal - (v_max * t_one);

	time_tl = (v_max - v_initial) / a_max;
	time_r = (d_two / v_max)

	t_total = (2 * time_t) + time_r;

}
