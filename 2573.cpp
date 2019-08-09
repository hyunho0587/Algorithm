#include <stdio.h>
#include <algorithm>
#include <queue>

#define X first
#define Y second
using namespace std;

#define MAX 300

int board[MAX][MAX] = {0};
int dist[MAX][MAX] = { 0 };

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

queue<pair <int, int>> Q;
int N, M;
bool finish = false;
void bfs() {
	int water = 0;
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			
			if (nx < 0 or nx >= N or ny < 0 or ny >= M) continue;
			if (dist[nx][ny] == 1) continue;
			if ((board[nx][ny] == 0) && (dist[nx][ny]==0)) {
				water++;
				continue;
			}
		//	printf("push: (%d %d)\n", nx, ny);
			Q.push({ nx,ny });
			dist[nx][ny] = 1;
		}
		if (board[cur.X][cur.Y] < water) {
			board[cur.X][cur.Y] = 0;
		}
		else { board[cur.X][cur.Y] -= water; 
		
		}
		water = 0;
	}
	
	//printf("next year\n");
}


int main() {
	
	
	int time = 0;
	int count = 0;
	int ice = 0;
	bool judge =true;
	scanf(" %d %d",&N,&M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	
	while (ice < 2) {
		ice = 0;
		
		

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] != 0 && dist[i][j] == 0) {
				//	printf("start: (%d %d)\n",i,j);
					Q.push({i,j});
					dist[i][j] = 1;
					bfs();
					ice++;
				//	printf("ice : %d\n", ice);
				}
				
			}
		}
		if (ice >= 2) break;
	/*	printf("ice result : %d\n", ice);
		printf("time: %d\n", time);
		printf("+++++++++++++++++++++++\n");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				printf(" %d", board[i][j]);
			}
			printf("\n");
		}
		printf("+++++++++++++++++++++++\n");*/
		for (int i = 0; i < N; i++) {
			fill(dist[i], dist[i] + M, 0);
		}
		//printf("검사시작\n");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {	
				if (board[i][j] != 0) {
					//printf("따빵\n");
					judge = false;
					break;
				}
			}
		}
		if (judge) {
			time = 0;
			break;
		}
		judge = true;
		//printf("\n");
		time++;
	}
	printf("%d\n",time);
}