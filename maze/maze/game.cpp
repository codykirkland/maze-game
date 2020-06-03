//the class loads the level prints the level moves the player and 
//when the player finishes the level it move on to the name one

#include "game.h"



using namespace std;


game::game()
{
	
	xp = 0;
	yp = 0;
	
}

//loads the level
void game::load(int fn) {

	ifstream fi;
	 
	string levelString = to_string(fn);//change a int to a string 
	string filelevel = "levels\\level" + levelString + ".txt";//get the file name
	

	l = fn;
	
	fi.open(filelevel);//opens the file
	
	//checks of the file is there 
	if (fi.fail()) {
		cout << "level did not open";
		complete = true;
		_getch();
		
	}
	string line;

	//puts the file into an vector
	while (getline(fi, line)) {
		lvl.push_back(line);

	}
	fi.close();//closes the file

	char t;
	//searchs the vector for the @ symbol 
	for (int y = 0; y < lvl.size(); y++)
	{
		for (int x = 0; x < lvl[y].size(); x++) {
			t = lvl[y][x];

			switch (t)
			{
			case'@':
				setp(x, y );//sets the position of the player
				break;

			}
		}
	}
}

//prints the level
void game::print() {

	cout << string(100, '\n');//prints 100 blank lines
	cout << "level  " << l << endl;
	//prints all the lines in the vector
	for (int i = 0; i < lvl.size(); i++) {
		

		cout << lvl[i] << endl;

	}
	cout << "use w/a/s/d to move" << endl;
}
//playes the game
void game::play() {


	//while complete is equal to false it will loop the print and move functions
	while (complete != true) {
		print();
		move();


	}

}
//gets the direction the player wants to move
void game::move() {



	char input;
	input = _getch();//gets the player input to move the character

	//this tells the chkmove function were the player wants to move
	switch (input) {
		
	case 'w':
	case 'W'://up
		chkmove(0, -1);

		break;

	case 's':
	case 'S'://down
		chkmove(0, 1);

		break;
	case 'a':
	case 'A'://left
		chkmove(-1, 0);

		break;
	case 'd':
	case 'D'://right
		chkmove(1, 0);

		break;
	default:
		cout << "invalid input" << endl;
			break;
	}

}
//moves the player
void game::chkmove(int x, int y) {

	int px, py;

	//gets the posiont of the player
	getp(px, py);
	
	//gets the position of where the player want to move
	 char mt = gett(px+ x, py + y);

		//checks if the player can move to the position 
		switch (mt) {
		
		case' ':

			//sets the new postion of the character
			setp(px+ x, py + y);

			//switches the space and the character
			sett(px, py, ' ');
			sett(px+ x, py + y, '@');
			break;
		case'F':
			
			//calls the next level
			next();
	
		
			break;
			
		}
		
}

//moves onto the next level
void game::next() {
	
	
	lvl.clear();//clears the vector

	//checks to see if you beat the game
	if (5==l) {

			cout << "congrats you finished the game" << endl;
			_getch();
			complete = true;
		}
	else
		{
		
	
	
			//loads the next level
		int nxx =l+1;
			cout << nxx << endl;

			load(nxx);
	
		}
	

}
