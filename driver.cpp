#include <iostream>
#include <fstream>
#include <string>
#include "Value_iteration.h"

using namespace std;

int main(int argc, char *argv[]) {
	
	Value_iteration value_iteration;
	value_iteration.valueIteration();

	cout << "Question 3" << endl << endl;
	cout << "Yes, if the reward function values are changed by the same factor,\nthe value V* will be changed by this factor but the optimal policy would remain unchanged.\nFor example, if the reward function value is doubled the value V* will also be doubled but the \noptimal policy will remain unchanged." << endl << endl;
 
 }