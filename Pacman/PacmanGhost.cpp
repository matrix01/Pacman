#include "Pacman.h"

void Pacman::ghostMove(){ //move ghost randomly
//	myfile.open("example1.txt");
	int x, y;
	for (int i = 0; i<21; i++)
	for (int j = 0; j<46; j++) if (line[i][j] == 'P'){ x = i; y = j; }  //find the pacman
	bfs(x, y);			//Run bfs from pacman to whole map
	moveCount++;		//How many times pacman moved
	int i;
	
	if (moveCount < 5) ghostInRun = 1;		//First 5 move only one ghost works
	else if (moveCount < 10) ghostInRun = 2;	//after 10 2 come out
	else if (moveCount < 15) ghostInRun = 3;		//after 15 3 come out
	else ghostInRun = maxGhost;						//all ghost works

		for (i = maxGhost-1; i >= maxGhost-ghostInRun; i--){		//Ghost move
			int r = gx[i], c = gy[i];
			int minx = 1100, miny = 1100, mindis = 900;				//for getting the lowest and highest distance from the pacman
			int maxx = 0, maxy = 0, maxdis = 0;
			for (int j = 0; j < 4; j++){			//checking all 4 direction
				int u = r + dx[j];					//New position
				int v = c + dy[j];
				if (advanceLevel == 0){		//Basic level
					if (valid(u, v) == true && (mindis>dist[u][v]) && line[u][v] != ghost){  //Pacman has no power
						minx = u;		//New position
						miny = v;
						mindis = dist[u][v];		//Min distance
					}
				}
				if (advanceLevel == 1){ //Advance level
					if (flag == false){
						if (valid(u, v) == true && (mindis > dist[u][v]) && line[u][v] != ghost){  //Pacman has no power
							minx = u;
							miny = v;
							mindis = dist[u][v];
						}
					}
					if (flag == true){
						if (valid(u, v) == true && dist[u][v] < 70 && (maxdis < dist[u][v]) && line[u][v] != ghost){ //Pacman has power
							maxx = u;
							maxy = v;		//new max distance from pacman
							maxdis = dist[u][v];	//max distance
						}
						minx = maxx;
						miny = maxy;
					}
				}
			}
			if (line[minx][miny] == 'P'&& valid(minx, miny)==true && flag==false) //If pacman has no power pacman and ghost reset
				reset();
			else if (line[minx][miny] == 'P'&& valid(minx, miny) == true && flag == true)
			{		//pacman has power and ghost position is the pacman position ghost die
				line[r][c] = tmp[i];
				tmp[i] = ' ';
				line[minx][miny] = 'P';
				gx[i] = tgx[i];		//ghost respawn position
				gy[i] = tgy[i];
				line[7][19] = ghost;
				gx[i] = 7;
				gy[i] = 19;
				eat += 200;
				system("CLS");
				PrintpacMap();
				cout << "Ghost eat pacman!" << endl;
			}
			else{
				char t = tmp[i];		
				tmp[i] = line[minx][miny];	
				line[minx][miny] = ghost;  //ghost move towards pacman
				line[r][c] = t;
				gx[i] = minx;
				gy[i] = miny;
				
			}
		}
}
