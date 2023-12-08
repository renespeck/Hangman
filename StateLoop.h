//concrete state class of state-pattern
#ifndef StateLoop_I2abdb221m12355049952mm1oamr_H
#define StateLoop_I2abdb221m12355049952mm1oamr_H

#include "State.h"
#include "Singleton.h"

#include <set>
#include <string>
//!  	concrete state class 
/*!	
	This class is a  concrete implementation of State.h  and a Singleton.h. 	
	Represent the loop state. 
*/
class StateLoop : public State, public Singleton<StateLoop>{
friend class Singleton<StateLoop>; 

public:
	~StateLoop(){ }
	
protected:
	/*!	\sa State.h	*/
	virtual void update();
	/*!	\sa State.h	*/
	virtual void doPrint();
	/*!	\sa State.h	*/
	virtual void doGetKey();
	/*!	\sa State.h	*/

private:
	int countFailAnswers,countTrueLetters;
	bool updateAvailable,solved;
	std::set<char> letters;
	std::string currentWord;

	StateLoop():
		countFailAnswers(0),updateAvailable(true),solved(false),currentWord(""){ 
	}
};
#endif // StateLoop_I2abdb221m12355049952mm1oamr_H

