#include "Pacman.h"
#include<queue>

void Pacman::bfs(int x, int y){
	for (int i = 0; i < 22; i++){
		for (int j = 0; j < 43; j++){
			dist[i][j] = 1000;
		}
	}
	for (int j = 0; j < 23; j++)
	for (int k = 0; k < 46; k++)
		vis[j][k] = false;
	
	queue<int> q;
//	myfile << "Pacman: " << x << " " << y << endl;
	q.push(x);
	q.push(y);
	dist[x][y] = 0;
	vis[x][y] = true;
	while (!q.empty()){
		int r = q.front(); q.pop();
		int c = q.front(); q.pop();


		for (int i = 0; i < 4; i++){
			int u = r + dx[i];
			int v = c + dy[i];

			//myfile<<"Visiting: " << u << " " << v <<" "<<dist[u][v]<< endl;
			if ((line[u][v] == ' ' || line[u][v] == '.' || line[u][v] == '-' || line[u][v] == 'o'||line[u][v]==ghost) && vis[u][v] == false && valid(u, v) == true){
				vis[u][v] = true;
				dist[u][v] = dist[r][c] + 1;
				q.push(u);
				q.push(v);
			}
			//cout << "Dist: " << u << " " << v <<" "<< dist[u][v] << endl;
		}
	}
	

/*	myfile << "After:" << endl;
	for (int i = 0; i < 22; i++){
		for (int j = 0; j < 43; j++){
			myfile << dist[i][j] << " ";
		}
		myfile << endl;
	}
	myfile << "After Done!" << endl;
	myfile.close();*/
}

void Pacman::dfs(int x, int y){
	visited1[x][y] = true;
	//myfile.open("example1.txt");
	//myfile << "visit: " << x << " " << y << endl;
	
	for (int i = 0; i < 4; i++){
		int u = x + dx[i];
		int v = y + dy[i];

		//			cout<<"Visiting: " << u << " " << v << endl;
		if ((line[u][v] == ' ' || line[u][v] == '.' || line[u][v] == '-' || line[u][v] == 'o') && visited1[u][v] == false && valid(u, v) == true && line[u][v] != 'P'){
			dist[u][v] = dist[x][y] + 1;
			dfs(u, v);
		}
	}
}
