#ifndef StateStart_I2abdb221m12355049952mm7cca_H
#define StateStart_I2abdb221m12355049952mm7cca_H
#include "State.h"
#include "Singleton.h"
//!  	concrete state class 
/*!	
	This class is a  concrete implementation of State.h  and a Singleton.h. 	
	Represent the start state. Only this state can set the game context defined in  GameContext.h.
*/
class StateStart : public State, public Singleton<StateStart>{
friend class Singleton<StateStart>; 

public:
	~StateStart();
	/*!	Set the GameContext for all other states 	 	*/
	void setGameContext(GameContext* gameContext);

protected:
	virtual void doPrint();
	virtual void doGetKey();

private:
	StateStart(){  }
};
#endif // StateStart_I2abdb221m12355049952mm7cca_H
