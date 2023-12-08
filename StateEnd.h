//concrete state class of state-pattern
#ifndef StateEnd_I2abdb221m12355049952mm7c7a_H
#define StateEnd_I2abdb221m12355049952mm7c7a_H

#include "State.h"
#include "Singleton.h"
//!  	concrete state class 
/*!	
	This class is a  concrete implementation of State.h  and a Singleton.h. 	
	Represent the end state. 
*/
class StateEnd : public State, public Singleton<StateEnd>{
friend class Singleton<StateEnd>; 

public:
	~StateEnd(){ }

protected:
	virtual void doPrint();
	virtual void doGetKey();

private:
	StateEnd(){ }
};
#endif // StateEnd_I2abdb221m12355049952mm7c7a_H

