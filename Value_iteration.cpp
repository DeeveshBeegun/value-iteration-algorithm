#include "Value_iteration.h"
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

std::string grid_world[ROW][COL] = {{"s4", "s5", "s6"}, {"s1", "s2", "s3"}};

int Value_iteration::reward(const State &state, const string &action) const{
	if(state.check_equal("s6") && perform_action(state, action).check_equal("s3"))
		return 100;	// return reward of 100

	else if(state.check_equal("s2") && perform_action(state, action).check_equal("s3"))
		return 50; // return reward of 50

	else 
		return 0; // no reward

}