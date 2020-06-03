//the class loads the level prints the level moves the player and 
//when the player finishes the level it move on to the name one

#include<vector>
#include <fstream>
#include <string>
#include <iostream>
#include <conio.h>


using namespace std;

class game
{
public:
	game();
	
	
	void load(int);//loads the level
	void print();//prints the level
	void play();//
	void move();//gets the direction tthe player wants to move
	void chkmove(int, int );//moves the player
	void next();//moves to the next leve

	//gets posiont of x and y
	char gett(int x, int y)
	{
		return lvl[y][x];

	}
	//sets ths postition on x and y
	void sett(int x, int y, char t)
	{
		lvl[y][x] = t;

	}
	//sets the position the player
	void setp(int x, int y) {
		xp = x;
		yp = y;
	}
	//gets the position of the player
	void getp(int& x, int& y) {
		x = xp;
		y = yp;
	}
	


	


private:
	vector <string> lvl;//the level 
	
	//saves were the player is
	int xp;
	int yp;


	bool complete = false;//if the game is finished it will switch to true
	int l;//what level the player is on
};

