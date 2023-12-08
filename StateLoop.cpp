#include "StateLoop.h"

#include "StateStart.h"
#include "GameContext.h"

#include <iostream>
#include <iterator> 
#include <vector>

//protected
void StateLoop::update(){
	if(!updateAvailable)   
		return ;
	updateAvailable = false;
	//reset - new round if solved or more than 5 wrong answers 
	if(solved || countFailAnswers > 5 ){				
		solved = false;
		countFailAnswers = 0;
		State::gameContext->generateNextWord();
		letters.erase(letters.begin(),letters.end());
	}
	//create new word
	currentWord = "";
	int countTrueLetters = 0;
	std::string word = State::gameContext->getWord();
	for(unsigned int i = 0; i < word.size(); i++ ){	
		//whitespace is a true letter and will count
		if( static_cast<char>(word[i]) == ' '){
			currentWord += " ";
			countTrueLetters++;
		}//check last inputs
		else if(letters.find(word[i]) == letters.end())
			currentWord += "*";
		else{
			currentWord += word[i]; //true input letter found
			countTrueLetters++;
		}
	}
	if(countTrueLetters == word.size())
		solved = true;
}
void StateLoop::doPrint(){
	clearConsole();	
	std::cout<<"Hangman Spiel\n-------------\n";
	std::cout<<"\n\n\n";
	std::cout<<"          "<<currentWord<<std::endl;	
	std::cout<<"          _____\n";
	std::cout<<"          |/   |\n";
	switch(countFailAnswers){
		case 0:
			std::cout<<"          |\n          |\n          |\n";
			break;
		case 1:
			std::cout<<"          |    O \n          |\n          |\n";
			break;
		case 2:
			std::cout<<"          |    O\n          |    |\n          |\n";
			break;
		case 3:
			std::cout<<"          |    O\n          |   \\|\n          |\n";
			break;
		case 4:
			std::cout<<"          |    O\n          |   \\|/\n          |\n";
			break;
		case 5:
			std::cout<<"          |    O\n          |   \\|/\n          |   /\n";
			break;
		case 6:
			std::cout<<"          |    O\n          |   \\|/\n          |   / \\ \n";			
			break;	
	}	
	std::cout<<"          |\n";
	std::cout<<"          OOOOOOOO\n\n";
	std::cout<<"          ";	
	std::copy(letters.begin(), letters.end(), std::ostream_iterator<char>(std::cout)); 
	std::cout<<"\n\n";
	if(countFailAnswers > 5)
		std::cout<<"          Das gesuchte Wort war: "<<State::gameContext->getWord();
	if(solved)
		std::cout<<"          Wort gefunden";
	std::cout<<"\n\n";
	if(countFailAnswers > 5 || solved)
		std::cout<<"1 Zurueck\n  Weiter mit beliebiger Taste\n"<<std::endl;
	else
		std::cout<<"1   Zurueck\nA-Z Antwort\n"<<std::endl;
	std::cout<<"Treffen Sie eine Wahl:";
}
void StateLoop::doGetKey(){
	
    std::cin.clear();
    std::cin.ignore(std::cin.rdbuf()->in_avail());	
	int number = std::cin.get();

	if(number == static_cast<int>('1')){
			State::gameContext->setState(StateStart::instance());
			//reset
			solved = true;
	}
	if(solved || countFailAnswers > 5 ){ 
		//ignore input, start new round
		updateAvailable = true;
		return;
	}

	//processing input
	//toUpper
	if(number >= static_cast<int>('a') && number <= static_cast<int>('z')){
		number -= 32; 
	}
	if(number >= static_cast<int>('A') && number <= static_cast<int>('Z')){
		int len = letters.size();
		letters.insert(static_cast<char>(number)); 
		if(len == letters.size()){
			std::cout<<"Eingabe vorhanden. Bitte wiederholen.\n";
			doGetKey();
			return ;
		}else{
			if(State::gameContext->getWord().find(static_cast<char>(number)) == std::string::npos)
				countFailAnswers++;
			else
				updateAvailable = true; //good letter
		}
	}else{
		std::cout<<"Keine gueltige Eingabe. Bitte wiederholen.\n"<<std::endl;
		doGetKey();
	}
}

