#include "profile.h"
#include <iostream>

int main() {
  Profile::ProfilePoint current;
  Profile::ProfilePoint goal;
  {
  	// Position (distance) of 'goal'
    goal.position = 1.0;
    // Velocity at 'goal'
    goal.velocity = 0.0;
  }

  Profile profile(current);
  profile.SetGoal(goal);

  // TRUE = will calculate using maximum velocity; FALSE = won't calculate using maximum velocity
  bool use_max_velocity = true;
  std::cout << profile.GetTime(current, goal, use_max_velocity) << std::endl;
}
