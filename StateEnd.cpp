#include "StateEnd.h"
#include "StateStart.h"
#include "GameContext.h"

#include <iostream>
//protected
void StateEnd::doPrint(){
	std::cout<<"Spiel beenden\n-------------\n";
	std::cout<<"\n\n\nSind Sie sich sicher?\n\n\n";
	std::cout<<"1 Zurueck\n2 Beenden\n"<<std::endl;
	std::cout<<"Treffen Sie eine Wahl:";
}
void StateEnd::doGetKey(){

	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	
	switch(static_cast<char>(std::cin.get())){
		case '2':
			State::gameContext->finish();
			break;	
		case '1':
			State::gameContext->setState(StateStart::instance());
			break;	
	}
}


