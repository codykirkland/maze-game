/*
It is a top-down maze game where the player will have to navigate through diferent
level to beat the game
*/
#include <iostream>



#include "game.h"
game Game;




int main() {

	
	int im;

	cout << "\nwelcome to the maze game\n" << endl;
	
	cout << "1. new game \n\n" << "2. select a level\n\n" << "3. exit\n\n" <<"Select Your Option(1 - 3) "
		<< endl;
	
		 cin>>im;
		
		 
	switch (im) {
	case 1://loads game from the first level
		
		Game.load(1);
		Game.play();
		break;
	case 2://loads game from a spcific level
		int sl;
		cout << "\nselect a level (1-5)"<<endl;
		cin >> sl;
		Game.load(sl);//loads spaciic level
		Game.play();//calls the play function to play the game
		
		break;
	case 3://exits the game
		return 0;
		break;
	default:
		cout << "invalid input" << endl;
		break;
	}
		
	return 0;
}

