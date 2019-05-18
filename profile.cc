#include "profile.h"
#include <cmath>
#include <iostream>

// NOTE - This is a very rough draft, and not a finished product. These are just some of the calculations I will be using
const double Profile::GetTime(ProfilePoint current, ProfilePoint goal, bool use_max_velocity) {
	// 'a' = acceleration
	double a = kMaxAcceleration;

	// 't' = time
	double t_accelerating;
	double t_decelerating;
	double t_constant_velocity;
	double t_total;

	// 'd' = distance
	double d_accelerating;
	double d_constant_velocity;
	double d_decelerating;

	// 'v' = velocity
	double v_initial = current.velocity;
	double v_max = kMaxVelocity;
	double v_goal = goal.velocity;

	// 'p' = position
	double p_beginning = current.position;
	double p_goal = goal.position;

	if (use_max_velocity) {
		// Time to reach the goal respecting ending at 0 velocity and `kMaxVelocity` and `kMaxAcceleration`
		t_accelerating = std::abs(v_max-v_initial) / a;
		t_decelerating = std::abs(v_goal-v_max) / a;

		d_accelerating = 0.5 * std::abs(v_max + v_initial) * t_accelerating;
		d_decelerating = 0.5 * std::abs(v_goal - v_max) * t_decelerating;

		d_constant_velocity = p_goal - d_accelerating - d_decelerating;
		t_constant_velocity = d_constant_velocity / v_max;

		t_total = t_accelerating + t_constant_velocity + t_decelerating;
	} else {
		t_total = (-v_initial + std::sqrt(std::pow(v_initial, 2) + (4 * .5 * a * goal.position))) / a;
	}

	return t_total;
}
