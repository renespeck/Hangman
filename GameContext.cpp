#include "GameContext.h"
#include <fstream>
#include <iostream>
#include <locale>
#include <algorithm> 
#include <vector>
//public
void GameContext::generateNextWord(){
	if(words.size() > 0 ){	
		word = words.front();
		words.pop_front();	
		words.push_back(word);
	}
}
//protected
//inherit from Game
bool GameContext::doInit(){
	state = StateStart::instance();
	StateStart::instance()->setGameContext(this);
	std::srand((unsigned)std::time(0));
	return true;
}
//inherit from Game
void GameContext::doLoop(){	
	state->update();	//member form state can be overwritten
	state->doPrint();	//overwritten by concrete State 
	state->doGetKey();	//overwritten by concrete State 
}
//private
bool GameContext::readWords(const std::string path){
	std::ifstream file(path.c_str(), std::ios_base::in); 
	if(!file.is_open())		
		return false;	
	//create allowed alphabet
	std::string alphabet = "";
	for(int i = static_cast<int>('A'); i <= static_cast<int>('Z');i++ ){
		alphabet += static_cast<char>(i);
	}
	alphabet += " "; 
	//
	std::vector<std::string> temp_vector;
	std::string line = "";
	std::locale loc;
	while (std::getline(file, line)){			//read file line by line
		line = trimString(line);		
		for (int i = 0; i < line.length(); ++i){	//check line char by char
			line[i] = toupper(line[i],loc);
			if (alphabet.find(line[i]) == std::string::npos){
				line = "";
				break;
			}			
		}//only words with a size of minWordSize  allowed
		if(line.size() >= minWordSize ) 
			temp_vector.push_back(line);
	}
	file.close();
	if(temp_vector.size() > 0 ){
		std::random_shuffle(temp_vector.begin(), temp_vector.end());
		//vectorToList
		words = std::list<std::string>(temp_vector.begin(),temp_vector.end()); 
		generateNextWord();
 		return true;
	}else
		return false;
}
std::string GameContext::trimString(std::string source,const std::string seq ){
	unsigned int first = source.find_first_not_of(seq); 
	unsigned int last = source.find_last_not_of(seq);    
	if(( std::string::npos == first ) || ( std::string::npos == last))
		return "";
	else
		return source.substr( first, last - first + 1 );
}
