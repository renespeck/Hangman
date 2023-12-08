#include "Game.h"
//public
Game::Game(){
	finished = true;
}
bool Game::run(){
	finished = false;
	if(doInit()){
		doPreProcess();
		while(!finished)
			doLoop();	
		doPostProcess();
	}
	return 0;
}
void Game::finish(){
	finished = true;
}


