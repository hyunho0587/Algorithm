#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define X first
#define Y second
#define MAX 300
int dx[8] = { 1,1,-1,-1,2,2,-2,-2 };
int dy[8] = { 2,-2,2,-2,1,-1,1,-1 };
int board[MAX][MAX] = { 0 };


int main() {
	int Test;
	int N;
	int start_x, start_y;
	int finish_x, finish_y;
	int num=0;
	
	vector <int> V;
	scanf(" %d",&Test);
	for (int i = 0; i < Test; i++) {
		int dist[MAX][MAX] = { 0 };
		queue<pair<int, int>> Q;
		scanf(" %d",&N);
		scanf(" %d %d",&start_x, &start_y);
		scanf(" %d %d", &finish_x, &finish_y);
		Q.push({ start_x, start_y });
		dist[start_x][start_y] = 1;
		
		
		while (!Q.empty()) {
			int size = Q.size();
			if (dist[finish_x][finish_y] == 1) break;
			for (int k = 0; k < size; k++) {
				
				auto cur = Q.front(); Q.pop();
				//printf("start: %d, %d\n",cur.X,cur.Y);
				for (int dir = 0; dir < 8; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					
					if (dist[nx][ny] == 1)continue;
					if (nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
					//printf("nxny: (%d,%d)\n", nx, ny);
					if (nx == finish_x && ny == finish_y) { dist[nx][ny] = 1;  continue; }
					Q.push({ nx,ny });
				
					dist[nx][ny] = 1;
					if (dist[finish_x][finish_y] == 1) break;
				}
			}

			//printf("num¡ı∞°\n");
			
			num++;
			if (dist[finish_x][finish_y] == 1) break;
		}
		
		V.push_back(num);
		num = 0;
		
	}
	
	for (int a = 0; a < V.size(); a++) {
		printf("%d\n",V[a]);
	}
}