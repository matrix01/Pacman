#include "Pacman.h"

void Pacman::ghostMove(){ //move ghost randomly
//	myfile.open("example1.txt");
	int x, y;
	for (int i = 0; i<21; i++)
	for (int j = 0; j<46; j++) if (line[i][j] == pacman){ x = i; y = j; }  //find the pacman
				//Run bfs from pacman to whole map
	bfs(x, y);
	moveCount++;		//How many times pacman moved
	if (moveCount < 5) ghostInRun = 1;		//First 5 move only one ghost works
	else if (moveCount < 10) ghostInRun = 2;	//after 10 2 come out
	else if (moveCount < 15) ghostInRun = 3;		//after 15 3 come out
	else ghostInRun = maxGhost;						//all ghost works

/*	for (int i = 3; i >=0; i--){
		gq.push(gx[i]);
		gq.push(gy[i]);
	}
	i = 3;
	while (!gq.empty()){
		int r = gq.front(); gq.pop();
		int c = gq.front(); gq.pop();
			int minx = 1100, miny = 1100, mindis = 900;				//for getting the lowest and highest distance from the pacman
			int maxx = 0, maxy = 0, maxdis = 0;
			for (int j = 0; j < 4; j++){			//checking all 4 direction
				int u = r + dx[j];					//New position
				int v = c + dy[j];
				if (advanceLevel == 0){		//Basic level
					if (valid(u, v) == true && (mindis>dist[u][v]) == true && ghostCheck(u, v) != true){  //Pacman has no power
						minx = u;		//New position
						miny = v;
						mindis = dist[u][v];		//Min distance
						//cout << "Pacman Pw: " << u << " " << v << " " << dist[u][v] << endl;
					}
				}
				if (advanceLevel == 1){ //Advance level
					if (flag == false){
						if (valid(u, v) == true && (mindis > dist[u][v]) == true && ghostCheck(u, v) != true){  //Pacman has no power
							minx = u;
							miny = v;
							mindis = dist[u][v];
						}
					}
					if (flag == true){
						if (valid(u, v) == true && dist[u][v] < 70 && (maxdis < dist[u][v]) == true && ghostCheck(u, v) != true){ //Pacman has power
							maxx = u;
							maxy = v;		//new max distance from pacman
							maxdis = dist[u][v];	//max distance
						}
						minx = maxx;
						miny = maxy;
						mindis = maxdis;
					}
				}
			}
			//cout << "Pacman Pw: " << minx << " " << miny << " " << dist[minx][miny] << endl;
			if (line[minx][miny] == pacman&& valid(minx, miny) == true && flag == false) //If pacman has no power pacman and ghost reset
				reset();
			else if (line[minx][miny] == pacman&& valid(minx, miny) == true && flag == true)
			{		//pacman has power and ghost position is the pacman position ghost die

				line[r][c] = tmp[i];
				tmp[i] = ' ';
				line[minx][miny] = pacman;
				line[7][19] = deadGhost;
				gx[i] = 7;
				gy[i] = 19;
				eat += 200;
			}
			else if (mindis > 100){
				if (i == 0)i = 3;
				gq.push(r);
				gq.push(c);
				i--;
				
			}
			else{
				char t = tmp[i];
				tmp[i] = line[minx][miny];
				if (flag == false)
					line[minx][miny] = ghost;  //ghost move towards pacman
				else line[minx][miny] = deadGhost;
				line[r][c] = t;
				gx[i] = minx;
				gy[i] = miny;
			}

		}*/
	queue<ghostP> tgq = gq;
	while (!gq.empty()) {
		gq.pop();
	}
	while (!tgq.empty()){
		ghostP g = tgq.front(); tgq.pop(); //stored ghost position
		ghostP gn;
		//cout<<"Looping: " << g.r << " " << g.c << endl;
		int mnx = 500, mny = 500, mnd = 500;
		int maxx = 0, maxy = 0, maxdis = 0;
		for (int i = 0; i < 4; i++){
			int u = g.r + dx[i];	//new ghost position
			int v = g.c + dy[i];
			if (valid(u, v) && (line[u][v] != '[' || line[u][v] != ']')&& ghostCheck(u,v)==false && dist[u][v]<100){ //If its a valid ghost way
				if (dist[u][v] < mnd){	//got the new min distance
					mnx = u;	//set the distance
					mny = v;
					mnd = dist[u][v];
				}
			}
		}
		cout<<"Why:" << mnx << " " << mny << endl;
		if (mnx == 500 || mny == 500){

			for (int e = 0; e < 4; e++)
			if (line[g.r + dx[e]][g.c + dy[e]] == ' ' || line[g.r + dx[e]][g.c + dy[e]] == '.' || ghostCheck(g.r + dx[e], g.c + dy[e]) == true){
				mnx = g.r + dx[e];
				mny = g.c + dy[e];
			}
		}
		if (line[mnx][mny] == pacman){ //new position is a pacman
			if (flag == false){		//ghost eat pacman
				life--;
				reset();
			}
			else{					//pacman eat ghost
				line[g.r][g.c] = g.prev;
				gn.r = 9;
				gn.c = 21;
				gn.prev = ' ';
				line[gn.r][gn.c] = deadGhost;
				gq.push(gn);
			}
		}
		else{		//ghost in a free way
			//cout << "crash" << endl;
			line[g.r][g.c] = g.prev;
			gn.r = mnx;
			gn.c = mny;
			if (line[mnx][mny] != 'G' || line[mnx][mny] != 'g')
				gn.prev = line[mnx][mny];
			else
				gn.prev = ' ';
			line[mnx][mny] = pacGhost;
			gq.push(gn);
		}
		k++;
	}
}
