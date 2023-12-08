#include "StateStart.h"
#include "GameContext.h"

#include "StateSettings.h"
#include "StateEnd.h"
#include "StateLoop.h"

#include <iostream>
//public 
StateStart::~StateStart(){  
	StateEnd::deleteInstance();
	StateSettings::deleteInstance();
	StateLoop::deleteInstance();
}
void StateStart::setGameContext(GameContext* gameContext){
		this->gameContext = gameContext;
};
//protected
void StateStart::doPrint(){
	std::cout<<"Willkommen bei Hangman\n----------------------\n";
	std::cout<<"\n\n\n"<<State::gameContext->getListCount()<<" Woerter geladen.\n\n\n";
	std::cout<<"1 Start\n2 Einstellungen\n3 Beenden\n"<<std::endl;
	std::cout<<"Treffen Sie eine Wahl:";
}
void StateStart::doGetKey(){
	
    std::cin.clear();
    std::cin.ignore(std::cin.rdbuf()->in_avail());
	
	switch(static_cast<char>(std::cin.get())){
		case '1':
			State::gameContext->setState(StateLoop::instance());
			break;
		case '2':
			State::gameContext->setState(StateSettings::instance());
			break;
		case '3':
			State::gameContext->setState(StateEnd::instance());
			break;
			
	}
}
