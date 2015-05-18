#define _CRT_SECURE_NO_WARNINGS
#include "Pacman.h"
#include <conio.h>
#include <queue>
using namespace std;

Pacman::Pacman(){  //constructor
	for (int i = 0; i < 4; i++)tmp[i] = road;
//	myfile.open("example1.txt");
	advanceLevel = 0;
	levelOver = true;

	c=0; stopWatch=25; moveCount=0; life=3; eat=0; flag=false; gameOver=true; //Setting all initial values
}
bool Pacman::ghostCheck(int x, int y){
	if (line[x][y] == ghost || line[x][y] == deadGhost)return true;
	else return false;
}
bool Pacman::eatCherry(int x, int y){
	if (line[x][y] == 'C' || line[x][y] == 'H' || line[x][y] == 'E' || line[x][y] == 'R' || line[x][y] == 'R' || line[x][y] == 'Y')
		return true;
	return false;
}
void Pacman::timer(){
	if (stopWatch>0 && flag==true)cout << "\tPower Left: " << stopWatch-- << endl;
	else{
		stopWatch = 25;
		flag = false;
		pacGhost = ghost;
	}
}
void Pacman::setGhost(){
	//cout<<"1: " << pacmanPower << endl;
	queue<ghostP> tg=gq;
	while (!gq.empty())gq.pop();
	int a = 0;
	while (!tg.empty()){
		cout << "crash here" << endl;
		ghostP pg = tg.front(); tg.pop();
		line[pg.r][pg.c] = pg.prev;
		line[gx[a]][gy[a]] = ghost;
		pg.r = gx[a];
		pg.c = gy[a];
		pg.prev = ' ';
		gq.push(pg);
		a++;
	}
	cout << a << endl;
	for (int i = 1; i < 20; i++){
		for (int j = 0; j < 45; j++){
			if (line[i][j] == pacman)line[i][j] = road;
		}
	}
	line[15][11] = 'P';
}
void Pacman::reset(){ //reset if pacman and ghost in same position
	if (life >= 1){
		moveCount = 0;
		setGhost();
		system("CLS");
		PrintpacMap();
	}
	else{
		end();
	}
}
void Pacman::end(){  //If no life left
	system("CLS");
	cout << "\tGame Over!"<< endl;
	cout << endl;
	cout << "\tTo Play Again Enter C: C" << endl;
	cout << "\tTo End The Game Enter E: E" << endl;
	char ch;
	cin >> ch;
	if (ch == 'c' || ch == 'C'){
		life = 3;
		levelOver = false;
		while (!gq.empty())gq.pop();
		for (int i = 0; i < 21; i++)
		for (int j = 0; j < 46; j++){
			vis[i][j] = false;
			dist[i][j] = 10000;
			visited1[i][j] = false;
			line[i][j] = ' ';
		}
		for (int i = 0; i < 10; i++){
			gx[i] = 0; gy[i] = 0;
			tmp[i] = ' ';
		}
		stopWatch = 25;
		flag = false;
	//	system("CLS");
		LoadpacMap();
		//PrintpacMap();
	}
	else{
		levelOver = false;
		gameOver = false;
	}

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

	/*Taking ghost position*/
	ghostP gp;
	int a = 0;
	while (!gq.empty())gq.pop();
	for (int i = 0; i < 21; i++)
	for (int j = 0; j < 45; j++) if (line[i][j] == ghost){ 
		gp.r = i;
		gp.c = j;
		gp.prev = ' ';
		gq.push(gp); //storing ghost in queue
		gx[a] = i;
		gy[a++] = j;
	}  //find the Ghost
	cout <<"Size: "<< a << " "<<gq.size()<<endl;
	cherry = 0;  //life increase
	pacGhost = ghost;  //Set the 'G' as ghost when pacman has no pawer;
}

void Pacman::PrintpacMap(){  //Print the pacmap
	for (int i = 0; i <= 20; i++)
		cout << line[i] << endl;
	cout << endl << endl;
	cout << "           Life: "<<life << endl;
	cout << "          Score: " << eat << endl;
	timer();
}

void Pacman::PacmanDir(){
		c = 0;
		//cout << c << endl;
		c = _getch();
		switch (c) {  //using key values as case
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
		while (pm.gameOver){
			//Sleep(200);
			//system("CLS");
			int levelSelection;
			cout << "\t1. Basic Level\n\t2. Advance Level\n" << endl;
			cin >> levelSelection;
			switch (levelSelection)
			{
			case 1:
				pm.advanceLevel = 0;
				pm.levelOver = true;
				break;
			case 2:
				pm.advanceLevel = 1;
				pm.levelOver = true;
				break;
			default:

				break;
			}
			//system("CLS");
			pm.LoadpacMap();
			pm.PrintpacMap();
			//pm.bfs(15, 11);
			while (pm.levelOver){
				pm.PacmanDir();
			}
		}
	return 0;
}
