#ifndef State_I2abdb221m12355049952mm7d0e_H
#define State_I2abdb221m12355049952mm7d0e_H

#include <iostream>

class GameContext;
//!  	abstract state.  
/*!	Abstract state of state pattern. Defined all states. 	*/
class State{

public:
	/*!	Use this Methode to update the state before doPrint() or doGetKey() is called. You can override.  Default implementation calls clearConsole(). 	*/
	virtual void update(){
		clearConsole();
	};
	/*!	Use this Methode to print state information. You have to override.	*/
	virtual void doPrint() = 0;
	/*!	Use this Methode to get an input information. You have to override.	*/
	virtual void doGetKey() = 0;
	State(){std::ios::sync_with_stdio(false);}
	virtual ~State(){ }

protected:
	/*!	Represent the context and allow concrete stats access to context data. Shared with all states.	*/
	static GameContext *gameContext; 
	/*!	Clear Windows console. You can override.	*/
	virtual void clearConsole(){
		#if defined _WIN32
			system("cls");
		#endif
	}
};
#endif // State_I2abdb221m12355049952mm7d0e_H 
