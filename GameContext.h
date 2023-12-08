#ifndef GameContext_I2abdb221m12355049952mm7d51_H
#define GameContext_I2abdb221m12355049952mm7d51_H

#include <list>

#include "Game.h"			
#include "State.h"			
#include "StateStart.h"			
//!  	concrete game algorithm. 
/*!	
	Context of state pattern and concrete game algorithm. Load and hold game data for concrete states.
	\sa State.h
	\sa Game.h		
*/
class GameContext : public Game{

public:
	/*!	Constructor.
		\param minWordSize the minimal word length, default is 4.
	*/
	GameContext(int const minWordSize = 4)
		:state(0),word(""),words(0),minWordSize(minWordSize){
	}
	~GameContext(){
		StateStart::deleteInstance();
	}
	/*!	Sets the state that will be used in this context. Access for concrete states.
		\param state represents the current concrete state. 	
	*/	
	void setState(State *state){	
		this->state = state;
	}
	enum LANGUAGE{DE,ENG,NL,FR};	 //
	/*!	Sets the state object that will be used in this context. Access for concrete state settings (stateSettings.h).
		\param lan represents the language that will be used and load with readWords(const std::string path).
	*/
	void setWords(LANGUAGE lan){
		switch(lan){
			case DE:
				readWords("wordlist/de.txt");
				break;
			case ENG:
				readWords("wordlist/eng.txt");
				break;
			case NL:
				readWords("wordlist/nl.txt");
				break;
			case FR:
				readWords("wordlist/fr.txt");
				break;
		}
	}
	/*!	Generate the next word to get it with getWord().  Access for concrete state loop	*/
	void generateNextWord();	
	/*!	Get the current word.  Access for concrete state loop	*/	
	std::string getWord()const{
		return word;
	}
	/*!	Get the current word count stored in this object.   Access for concrete state start	*/	
	int getListCount()const{
		return words.size();
	}
protected:
	/*!	A implementation of the primitive operation inherit from Game. 
		Set the default state start and the game context to all other states.
		Initialized  the PRNG.
	*/
	virtual bool doInit();
	/*!	A implementation of the primitive operation inherit from Game. 
		A template method to call current state object methods in a loop.
	*/
	virtual void doLoop();	

private:
	/*!	current state		*/
	State *state;
	/*!	all words with a minimal size of minWordSize	*/
	std::list<std::string> words;
	/*!	current word	*/
	std::string word;
	/*!	minimal word size initialized by constructor 	*/
	int const minWordSize;
	/*!	read a words from file*/
	bool readWords(const std::string path);
	/*!	remove whitespaces or a custom string sequence	*/
	std::string trimString(std::string source,const std::string seq = " \t");	
};
#endif // GameContext_I2abdb221m12355049952mm7d51_H
