//concrete state class of state-pattern
#ifndef StateSettings_I2abdb221m12355049952mm7a91_H
#define StateSettings_I2abdb221m12355049952mm7a91_H

#include "State.h"
#include "Singleton.h"
#include "StateStart.h"

#include <string>
//!  	concrete state class 
/*!	
	This class is a  concrete implementation of State.h  and a Singleton.h. 	
	Represent the settings state. 
*/
class StateSettings : public State, public Singleton<StateSettings>{
friend class Singleton<StateSettings>; 

public:
	~StateSettings(){ };
	
protected:
	virtual void doPrint();
	virtual void doGetKey();

private:
	StateSettings(){ }
};
#endif // StateSettings_I2abdb221m12355049952mm7a91_H

