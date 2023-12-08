#include "StateSettings.h"

#include "StateStart.h"
#include "GameContext.h"

#include <iostream>
//protected
void StateSettings::doPrint(){
	std::cout<<"Spiel-Einstellungen\n-------------------\n";
	std::cout<<"\n\n\n\n\n\n";
	std::cout<<"1 Zurueck\n2 De\n3 Eng\n4 Nl\n5 Fr\n"<<std::endl;
	std::cout<<"Treffen Sie eine Wahl:";
}
void StateSettings::doGetKey(){
	
    std::cin.clear();
    std::cin.ignore(std::cin.rdbuf()->in_avail());
	
	switch(static_cast<char>(std::cin.get())){
		case '1':
			State::gameContext->setState(StateStart::instance());
			break;	
		case '2':
			State::gameContext->setWords(GameContext::DE);	
			State::gameContext->setState(StateStart::instance());
			break;	
		case '3':
			State::gameContext->setWords(GameContext::ENG);
			State::gameContext->setState(StateStart::instance());
			break;
		case '4':
			State::gameContext->setWords(GameContext::NL);	
			State::gameContext->setState(StateStart::instance());
			break;	
		case '5':
			State::gameContext->setWords(GameContext::FR);
			State::gameContext->setState(StateStart::instance());
			break;
	}
}


