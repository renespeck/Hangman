/*! \mainpage Hangman Documentation

	A simple hangman game programmed in C++ 
	using the state design pattern and template method pattern.\n		
	Produced as part of a student research project in software design patterns.\n
	\n\n
	\author Rene Speck

 */
 #include "GameContext.h"
//main
int main(){
	int minWordSize = 7;
	GameContext *gc = new GameContext(minWordSize);
	gc->run();

	delete gc;	
	return 0;
}
