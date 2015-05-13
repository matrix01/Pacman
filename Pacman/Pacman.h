#ifndef Pacman_H
#define Pacman_H
#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>
#include<process.h>
#include<conio.h>
#include<queue>
using namespace std;
/*Direction of map*/
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, -2, 0, 2 };

/*Define arrow keys*/
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

/*Define pacman Moves*/
#define UP -1
#define DOWN 1
#define LEFT -2
#define RIGHT 2

/*Map Elements*/
#define food '.'
#define ghost 'G'
#define deadGhost 'x'
#define road ' '
#define bigPallet  'o'

#define mapHeight 20
#define mapWidth 45
#define numGhost 5

class Pacman{					//Pacman class
	
	string line[25];			//Pacmap
	int c = 0, eat = 0, life = 3, stopWatch = 25, moveCount = 0;
	int gx[10], gy[10], maxGhost, ghostInRun;; //for ghost
	int tgx[10], tgy[10];
	int dist[23][46];  //distance from pacman to each position of map

	bool vis[23][43];	//for bfs
	bool pacPower = false;
	bool visited1[23][43];
	bool flag = false;

	char tmp[5]; 
	ofstream myfile; //write in file

public:
	bool gameOver = true;
	Pacman();
	void LoadpacMap();  //Load map from txt
	void PrintpacMap();	//Print map
	void PacmanMove(int, int);  //detect Pacman direction from Keyboard Arrow keys
	void movePacman(int , int, int , int);
	void PacmanDir();
	bool interupt();
	void ghostMove();
	bool valid(int, int);
	void reset();
	void end();
	void bfs(int, int);
	void dfs(int, int);
	void setGhost();

};
#endif