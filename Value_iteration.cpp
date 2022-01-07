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

State Value_iteration::perform_action(const State &current_state, const string &action) const {
	State state(current_state.row, current_state.col);

	if(state.check_equal("s3"))
		return state; 
	if(action == "up" && state.row != 1)
		state.row += 1; // move up
	else if(action == "down" && state.row != 0) 
		state.row -= 1; // move down
	else if(action == "right" && state.col != 2)
		state.col += 1; // move right
	else if(action == "left" && state.col != 0)
		state.col -= 1; // move left

	return state;
 }

void Value_iteration::valueIteration() {

	bool not_converge = true; // repeat until converge
	float discount_factor = 0.8; // gamma
	float value_functionOld = 0, probability = 1.0, threshold = 0.01; // iterate while a certain threshold is reached
	int iteration = 0;

	vector<State> stateVec;
	for(int i = 0; i < ROW; i++) {
 			for(int j = 0; j < COL; j++) {
 				State state(i, j);
 				stateVec.push_back(state); // states
 			}
 		}

 	float v_array[STATES_NO] = {}; // initialize array v arbitrarily
	for(int i = 0; i < STATES_NO; i++) {
		v_array[i] = 0;
	}

 while(not_converge) {
 		float change = 0; // difference between old and new (delta)
 		iteration++;

 	for (auto state : stateVec) {
 		vector<float> v_arrayVec;
	 	value_functionOld = v_array[convert2d_to_1d(state)];

		for(int i = 0; i < NO_ACTIONS; i++) {
			v_arrayVec.push_back(probability *(reward(state, actions[i]) + discount_factor*v_array[convert2d_to_1d(perform_action(state, actions[i]))]));

		}

 			v_array[convert2d_to_1d(state)] = *max_element(v_arrayVec.begin(), v_arrayVec.end());
 			change = max(change, abs(value_functionOld - v_array[convert2d_to_1d(state)]));

	}

		if(change < threshold) {
			not_converge = false; // converges
			iteration++;
		}

	}


string optimal_policy[STATES_NO] = {};
for(int i = 0; i < STATES_NO; i++) {
	optimal_policy[i] = "";
} 

// policy iteration
for (auto state : stateVec) {
	vector<string> action;
	vector<float> policy_valueVec;
	int optimal_actionIndex = 0;
	string optimal_action = "";

	//cout << state << endl;
	for(int i = 0; i < NO_ACTIONS; i++) {
		policy_valueVec.push_back(probability*(reward(state, actions[i]) + discount_factor*v_array[convert2d_to_1d(perform_action(state, actions[i]))]));
		action.push_back(actions[i]);
	}

	float key = *max_element(policy_valueVec.begin(), policy_valueVec.end());
	
	auto itr =  find(policy_valueVec.begin(), policy_valueVec.end(), key);
	optimal_actionIndex = std::distance(policy_valueVec.begin(), itr);
	
	optimal_action = action[optimal_actionIndex];

	optimal_policy[convert2d_to_1d(state)] = optimal_action;
	
	
}

		cout << "Question 1" << endl << endl;
		cout << "Number of iterations for the value iteration to converge: " << iteration << endl << endl;

		int index = 0;

		cout << "Optimal Values (V*): "  << endl;
		for(auto i : v_array) {
			cout << grid_world[convert1d_to_2d(index).row][convert1d_to_2d(index).col] << " " << i << endl;
			index++;
		}

		cout << endl;

		findState(optimal_policy);
	
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
