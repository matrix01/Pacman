#include "Pacman.h"
#include <windows.h>
void Pacman::movePacman(int x, int y, int dx, int dy){
	int r = x + dx, c = y + dy; //new position of pacman
	//cout << "4: " << pacmanPower << endl;
	if ((line[r][c] == road || line[r][c] == food || ghostCheck(r,c) ||eatCherry(r,c))&&valid(r,c)){ //if there is no obstacle in the path pacman moves up
		line[x][y] = road;  // Eating the food in the way

		if (line[r][c] == food)eat += 10; //adding 10 for eating food

		if (eatCherry(r, c) == true){		//if pacman eat a cherry
			cherry++;						//cherry count increase
			line[r][c] = pacman;		
			if (cherry == 6){		//if all 5 letter eaten life increases
				life++;
				cherry = 0;
			}
		}

		if (ghostCheck(r, c) == true && flag == false){  //if pacman meets ghost and pacman has no power
			life--;
			//Sleep(100);
			reset(); //reset the map
		}
		else if (ghostCheck(r, c)==true && flag == true){
			line[x][y] = road;
			eat += 200;
			line[r][c] = pacman;
			line[9][21] = pacGhost;
			system("CLS");		//Clear the console
			PrintpacMap();		//print the updated pacman Map
		//	cout << "From Here" << endl;
		}
		else{
			line[r][c] = pacman;    //pacman new position
			ghostMove();
			system("CLS");		//Clear the console
			PrintpacMap();		//print the updated pacman Map
		}
		c = 0;
	}
	else if (line[r][c] == bigPallet){
		if (flag == false){
			line[x][y] = road;
			eat += 50;
			line[r][c] = pacman;
			flag = true;
			//Sleep(100);
			pacGhost = deadGhost;
			/*for (int i = 0; i < 4; i++){
				line[gx[i]][gy[i]] = deadGhost;
			}*/
		//	Sleep(100);
			system("CLS");
			PrintpacMap();
		}
		else{
			line[x][y] = road;
			eat += 50;
			line[r][c] = pacman;
			stopWatch = 25;
		//	Sleep(100);
			system("CLS");
			PrintpacMap();
		}
	//	timer();
	}
}
void Pacman::PacmanMove(int dx, int dy){
	int x, y;
	for (int i = 0; i<21; i++)
	for (int j = 0; j<46; j++) if (line[i][j] == pacman){ x = i; y = j; }  //fine the pacman

	c = 0;
	if (dy == 0 && dx == -1){   //UP MOVE
		movePacman(x, y, dx, dy);
	}
	else if (dy == 0 && dx == 1){  //Down Move
		movePacman(x, y, dx, dy);
	}
	else if (dy == -2 && dx == 0){  //Left Move
		if (x == 9 && y == 3) {
			y = 43;
			line[x][3] = road;
			line[x][43] = pacman;
		}
		else
		movePacman(x, y, dx, dy);
	}
	else if (dy == 2 && dx == 0){  //Right Move
		if (x == 9 && y == 43) {
			y = 1;
			line[x][43] = road;
			line[x][y] = pacman;

		}
		else{
			movePacman(x, y, dx, dy);
		}
	}
}
