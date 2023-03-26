/*
 * State.h
 *
 *  Created on: Jan 29, 2017
 *      Author: carlos
 */

#ifndef STATE_H_
#define STATE_H_

#include <vector>
using namespace std;

class State {

public:

	/**This function returns the first state of the problem
	 * @return the initial state of the problem
	 */
	static State* getInitialState();


	/**
	 * This function returns a vector with the state successors of the provided one.
	 * @param[in] state State from which successors are generated
	 * @return A dynamically reserved object of the vector class with dynamically reserved states successors of the one provided. It is your responsability to liberate the reserved memory
	 */
	virtual vector<State*>* getSuccessors()=0;

	/**
	 * This function informs if the state is objective or it is not
	 * @return true if the state is objective. false otherwise.
	 */
	virtual bool isObjective()=0;

	/**
	 * This function prints out the state
	 */
	virtual void print()=0;

	/**
	 * This function allows the user to set some initial parameters of the problem
	 */
	static void setParameters(void *parameters);
};


#endif /* STATE_H_ */
