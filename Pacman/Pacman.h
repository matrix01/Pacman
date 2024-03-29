#ifndef Pacman_H
#define Pacman_H
#include<iostream>
#include<fstream>
#include<string>
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

#define deadGhost 'g'
#define road ' '
#define bigPallet  'o'
#define pacman 'P'

#define mapHeight 20
#define mapWidth 45
#define numGhost 5
#define ghostComp(a,b) (line[a][b]=='G'||line[a][b]=='g')

struct ghostP{
	int r, c;
	char prev;
};

class Pacman{					//Pacman class
	queue<ghostP>gq;
	string line[25];			//Pacmap
	int c, eat, life, stopWatch, moveCount, cherry;
	int gx[10], gy[10], maxGhost, ghostInRun, respawn; //for ghost
	//int tgx[10], tgy[10];
	int dist[23][46];  //distance from pacman to each position of map
	int k=0;
	char pacGhost;

	bool vis[23][47];	//for bfs
	bool visited1[23][47];
	bool flag;

	char tmp[10]; 
	ofstream myfile; //write in file

public:
	bool gameOver;
	bool levelOver;
	int advanceLevel;
	Pacman();
	void LoadpacMap();  //Load map from txt
	void PrintpacMap();	//Print map
	void PacmanMove(int, int);  //detect Pacman direction from Keyboard Arrow keys
	void movePacman(int , int, int , int);
	void PacmanDir();
	void ghostMove();
	bool valid(int, int);
	void reset();
	void end();
	void bfs(int, int);
	void dfs(int, int);
	void setGhost();
	void timer();
	bool eatCherry(int, int);
	bool ghostCheck(int, int);
};
#endif
