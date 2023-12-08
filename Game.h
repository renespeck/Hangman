#ifndef Game_I2abdb221m12355049952mm7d6a_H
#define Game_I2abdb221m12355049952mm7d6a_H
//!  	abstract algorithm controls the game  
/*!	This class use template method pattern.	*/
class Game{

public:
	/*!	The abstract constructor. Cant use in this context.	*/
	Game();
	/*!	The template method to initialize and  start game loop. Dont override.	*/
	bool run();		
	/*!	A concrete method to stop game loop. Dont override. 	*/
	void finish();	
	virtual ~Game(){ }

protected:
	/*!	A primitive operation called one time to initialize some data. You have to override.	*/
	virtual bool doInit() = 0;		
	/*!	A hook operation called before game loop starts. You can override.	*/
	virtual void doPreProcess(){ }	
	/*!	A primitive operation called in a loop until the finish()  method stop the loop. You have to override.	*/
	virtual void doLoop() = 0;		
	/*!	A hook operation called after game loop ends. You can override.	*/
	virtual void doPostProcess(){ }

private:
	/*!	hold the finished state	*/
	bool finished;
};
#endif // Game_I2abdb221m12355049952mm7d6a_H
