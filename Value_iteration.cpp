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

void Value_iteration::findState(string optimal_policy[]) {
	State starting_state(1, 0);
	State ending_state(1, 2);
	State state = starting_state;


cout << "Question 2" << endl << endl;
cout << "States that form the optimal policy(pi*) to reach the terminal state (s3):" << endl;

cout << grid_world[starting_state.row][starting_state.col];

while(grid_world[state.row][state.col] != "s3") {

	state = perform_action(state, optimal_policy[convert2d_to_1d(state)]);
	cout << "->" << grid_world[state.row][state.col];
	
	}
	cout << endl << endl;
	
}

 bool State::check_equal(const std::string &stateR) const{
	if(stateR == grid_world[this->row][this->col]) {
		return true;
	}

	return false;
}

ostream& operator<<(ostream& os, const State &state) {
		os << state.row << " " << state.col;
}

int Value_iteration::convert2d_to_1d(const State &state) const {
	int row = state.row;
	int col = state.col;
	int index = (row*COL + col);
	return index;
}

State Value_iteration::convert1d_to_2d(const int index) const {
	State state;
	if(index > COL) {
		state.row = 1;
		state.col = index - COL;
		return state;
	}

	state.row = 0;
	state.col = index;
	return state;

}
