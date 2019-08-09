#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
#define MAX 100
int board[MAX][MAX] = { 0 };
int dist[MAX][MAX] = { 0 };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	int rain_max = 0;
	int range_max = 0;
	queue<pair<int,int>> Q;
	int rain=0;
	int N;
	scanf(" %d",&N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %d", &board[i][j]);
			if (board[i][j] > rain_max) rain_max = board[i][j];
			
		}
	}
	for (int a = 0; a <= rain_max; a++) {
		
		int range = 0;
		printf("=====================\n");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (dist[i][j] == 0 && board[i][j]>a) { 
					Q.push({ i,j });
					dist[i][j] = 1;
					range++;
					printf("start: %d,%d\n", i, j);
					
				}
				while (!Q.empty()) {
					auto cur = Q.front();
					Q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
						if (dist[nx][ny] == 1) continue;
						if (board[nx][ny] <= a) continue;
						printf("nx : %d ny:%d\n", nx, ny);
						Q.push({ nx,ny });
						//printf("push: (%d,%d)\n", nx, ny);
						dist[nx][ny] = 1;
					}
				}
			}
		}
		
		if (range_max < range) range_max = range;
		//printf("%d : %d\n", a, range);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = 0;
			}		
		}
	}
	printf("%d",range_max);
}
