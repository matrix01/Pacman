#include "Pacman.h"

void Pacman::PacmanMove(int dx, int dy){
	int x, y;
	for (int i = 0; i<21; i++)
	for (int j = 0; j<46; j++) if (line[i][j] == 'P'){ x = i; y = j; }  //fine the pacman

	c = 0;
	if (dy == 0 && dx == -1){   //UP MOVE
		int r=x+dx, c=y+dy; //new position of pacman

		if (line[r][c] == road || line[r][c] == food || line[r][c]== ghost){ //if there is no obstacle in the path pacman moves up
			line[x][y] = road;  // Eating the food in the way
			
			if (line[r][c] == food)eat += 10; //adding 10 for eating food
		
			if (line[r][c] == ghost && pacPower==false){  //if pacman meets ghost and pacman has no power
				life--;
				reset(); //reset the map
			}
			else{
				line[r][c] = 'P';    //pacman new position
				ghostMove();
				system("CLS");		//Clear the console
				PrintpacMap();		//print the updated pacman Map
			}
			c = 0;
		}
		else if (line[r][c] == bigPallet){
			line[x][y] = road;
			eat += 50;
			line[r][c] = 'P';
			pacPower = true;
			system("CLS");
			PrintpacMap();
		}
	}
	else if (dy == 0 && dx == 1){  //Down Move
		int r = x + dx, c = y + dy; //new position of pacman

		if (line[r][c] == road || line[r][c] == food || line[r][c] == ghost){ //if there is no obstacle in the path pacman moves up
			line[x][y] = road;  // Eating the food in the way

			if (line[r][c] == food)eat += 10; //adding 10 for eating food

			if (line[r][c] == ghost && pacPower == false){  //if pacman meets ghost and pacman has no power
				life--;
				reset(); //reset the map
			}
			else{
				line[r][c] = 'P';    //pacman new position
				ghostMove();
				system("CLS");		//Clear the console
				PrintpacMap();		//print the updated pacman Map
			}
			c = 0;
		}
		else if (line[r][c] == bigPallet){
			line[x][y] = road;
			eat += 50;
			line[r][c] = 'P';
			pacPower = true;
			system("CLS");
			PrintpacMap();
		}
	}
	else if (dy == -2 && dx == 0){  //Left Move
		if (x == 9 && y == 1) {
			y = 43;
			line[x][1] = ' ';
			line[x][43] = 'P';

		}
		int r = x + dx, c = y + dy; //new position of pacman
		cout<<"RC: " << r <<" "<< c << endl;
		if (line[r][c] == road || line[r][c] == food || line[r][c] == ghost && valid(r, c)==true){ //if there is no obstacle in the path pacman moves up
			line[x][y] = road;  // Eating the food in the way

			if (line[r][c] == food)eat += 10; //adding 10 for eating food

			if (line[r][c] == ghost && pacPower == false){  //if pacman meets ghost and pacman has no power
				life--;
				reset(); //reset the map
			}
			else{
				line[r][c] = 'P';    //pacman new position
				cout << "P moved" << endl;
				ghostMove();
				cout << "G moved" << endl;
				system("CLS");		//Clear the console
				PrintpacMap();		//print the updated pacman Map
			}
			c = 0;
		}
		else if (line[r][c] == bigPallet){
			line[x][y] = road;
			eat += 50;
			line[r][c] = 'P';
			pacPower = true;
			system("CLS");
			PrintpacMap();
		}
	}
	else if (dy == 2 && dx == 0){  //Right Move
		if (x == 9 && y == 43) {
			y = 1;
			line[x][43] = ' ';
			line[x][y] = 'P';

		}
		else{
			int r = x + dx, c = y + dy; //new position of pacman

			if (line[r][c] == road || line[r][c] == food || line[r][c] == ghost){ //if there is no obstacle in the path pacman moves up
				line[x][y] = road;  // Eating the food in the way

				if (line[r][c] == food)eat += 10; //adding 10 for eating food

				if (line[r][c] == ghost && pacPower == false){  //if pacman meets ghost and pacman has no power
					life--;
					reset(); //reset the map
				}
				else{
					line[r][c] = 'P';    //pacman new position
					ghostMove();
					system("CLS");		//Clear the console
					PrintpacMap();		//print the updated pacman Map
				}
				c = 0;
			}
			else if (line[r][c] == bigPallet){
				line[x][y] = road;
				eat += 50;
				line[r][c] = 'P';
				pacPower = true;
				system("CLS");
				PrintpacMap();
			}
		}
	}
}
