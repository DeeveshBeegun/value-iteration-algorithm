#include <string>
#include <iostream>
#include <vector>

#ifndef _VALUE_ITERATION_H
#define _VALUE_ITERATION_H

#define ROW 2 // row size
#define COL 3 // column size
#define NO_ACTIONS 4 // number of actions
#define STATES_NO 6 // number of states

// state of agent
struct State {
	
	int row = 0, col = 0;

	State(int row, int col): row{row}, col{col} {}; // constructor to initialize state
	State(): row(row), col{col} {}; // defualt constructor

	bool check_equal(const std::string &stateR) const; // checks if two states are equal

	// outputs state in the form (row, column)
	friend std::ostream& operator<<(std::ostream& os, const State& state);
};

class Value_iteration {

public:
	std::string actions[NO_ACTIONS] = {"left", "right", "up", "down"}; // type of actions agent can perform

public:

	// provides reward after performing an action from a state
	int reward(const State &state, const std::string &action) const;

	// performs an action i.e move up, down, left or right, in a state
	State perform_action(const State &current_state, const std::string &action) const;

	// preform value iteration 
	void valueIteration();

	// output deterministic policy
	void findState(std::string optimal_policy[]);

	// convert a state to a 1d index
	int convert2d_to_1d(const State &state) const;

	// convert a 1d index into 2d index
	State convert1d_to_2d(const int index) const;


};



#endif