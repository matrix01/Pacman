#define _CRT_SECURE_NO_WARNINGS
#include "Pacman.h"

Pacman::Pacman(){  //constructor
	for (int i = 0; i < 4; i++)tmp[i] = road;
	myfile.open("example1.txt");
}
void Pacman::reset(){ //reset if pacman and ghost in same position
	for (int i = 0; i < 5; i++)gx[i] = 0, gy[i] = 0;
	system("CLS");
	LoadpacMap();
	PrintpacMap();
}
void Pacman::end(){  //If no life left
	system("CLS");
	cout << "Game Over!"<< endl;
}

bool Pacman::valid(int r, int c){  //if current row column is inside the grid
	if (r > 0 && r < 20 && c > 2 && c < 44) return true;
	return false;
}
void Pacman::LoadpacMap(){
	ifstream in;
	
	in.open("test.txt"); //opening the pacmap txt
	if (in.is_open())
	{
		int i = 0;
		while (getline(in, line[i++]))  //storing the txt into 2dimentional string
		{
			//cout << line[i-1] << '\n';
		}
		in.close();
	}
	else
		cout << "Can't open file!" << endl; //if pacmap does not available
	int a = 0, b = 0;
	for (int i = 0; i<21; i++)
	for (int j = 0; j < 45; j++) if (line[i][j] == ghost){ gx[a++] = i, gy[b++] = j; }  //find the Ghost
	maxGhost = a;
	for (int i = 0; i < maxGhost; i++){
		myfile << gx[i] << " " << gy[i] << endl;
	}
}



void Pacman::PrintpacMap(){  //Print the pacmap
	for (int i = 0; i <= 20; i++)
		cout << line[i] << endl;
	cout << endl << endl;
	cout << "           Life: "<<life << endl;
	cout << "          Score: " << eat << endl;
	if (pacPower == true && stopWatch > 0){
		cout << "\tPower Left : " << stopWatch-- << endl;
	}
	else{
		pacPower = false;
		stopWatch = 25;
	}
	
}

void Pacman::PacmanDir(){
		c = 0;
		//cout << c << endl;
		switch (c = _getch()) {  //using key values as case
		case KEY_UP:	//if key up pressed
			//cout << c << endl;
			PacmanMove(UP, 0);
			c = 0;
			//cout << "End UP" << endl;
			break;
		case KEY_DOWN:		//down key pressed
			PacmanMove(DOWN, 0);
			c = 0;
			break;
		case KEY_LEFT:
			PacmanMove(0, LEFT);	//left key pressed
			c = 0;
			//cout << "LEFT_KEY" << endl;
			break;
		case KEY_RIGHT:
			PacmanMove(0, RIGHT);  // key Right
			c = 0;
			break;
		default:
			//cout << endl << "null" << endl;  // key left
			break;
		}
}

int main(){
	Pacman pm;
	pm.LoadpacMap();
	pm.PrintpacMap();
	//pm.bfs(15, 11); 
	while (true){
		//Sleep(200);
		pm.PacmanDir();
	}
	return 0;
}
