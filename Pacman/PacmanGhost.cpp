#include "Pacman.h"

void Pacman::ghostMove(){ //move ghost randomly
//	myfile.open("example1.txt");
	int x, y;
	for (int i = 0; i<21; i++)
	for (int j = 0; j<46; j++) if (line[i][j] == 'P'){ x = i; y = j; }  //find the pacman
	bfs(x, y);
	moveCount++;
	int i;
	//cout << "Ghost found: "<<gx[0]<<" "<<gy[0] << endl;
	
	if (moveCount < 5) ghostInRun = 1;
	else if (moveCount < 10) ghostInRun = 2;
	else if (moveCount < 15) ghostInRun = 3;
	else ghostInRun = maxGhost;

	//myfile <<"Max Ghost: "<< maxGhost << endl;
		for (i = maxGhost-1; i >= maxGhost-ghostInRun; i--){
		//	cout << "New Ghost POS: " << gx[i] << " " << gy[i] << endl;
			int r = gx[i], c = gy[i];
			int minx = 1100, miny = 1100, mindis = 900;
			for (int j = 0; j < 4; j++){
				int u = r + dx[j];
				int v = c + dy[j];
		//		cout << "New pOst: " << u << " " << v << " " << dist[u][v] << endl;
				if (valid(u, v)==true && (mindis>dist[u][v])&&line[u][v]!=ghost){
					minx = u;
					miny = v;
					mindis = dist[u][v];
				}
					
			}
			cout << minx << " " << miny << endl;
			if (line[minx][miny] == 'P'&& pacPower!=true)
				reset();
			else{
			//	cout << "pre: " <<i<<" "<< tmp[i];
				char t = tmp[i];
				tmp[i] = line[minx][miny];
				line[minx][miny] = ghost;
				line[r][c] = t;
			//	cout << "  New tmp: "<<i<<" " << tmp[i] << endl;
				gx[i] = minx;
				gy[i] = miny;
				
			}
		}
}
