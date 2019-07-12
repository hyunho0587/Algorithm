#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100

int dist[MAX][MAX][MAX]; // 해당 칸을 방문했는지 여부를 저장
int n, m,h;
int dx[6] = { 1,0,-1,0 ,0,0};
int dy[6] = { 0,1,0,-1 ,0,0}; // 상하좌우위아래 6 방향을 의미
int dz[6] = { 0,0,0, 0, 1,-1 };
int board[MAX][MAX][MAX];
struct tomato {
	int x, y, z;
	tomato(int tz, int ty, int tx) {
		x = tx;
		y = ty;
		z = tz;
	}
};
int main() {
	int time = 0;
	queue<tomato> Q;
	scanf(" %d %d %d", &m, &n,&h);
	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			fill(dist[i][j], dist[i][j] + m, -1);


		
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				scanf(" %d", &board[i][j][k]);
				if (board[i][j][k] == 1) {
					Q.push(tomato(i, j, k));
					dist[i][j][k] = 1;
				}
			}
		}
	}//setting 

	while (!Q.empty()) {
		int size = Q.size();
		for (int i = 0; i < size; i++) {
			tomato t = Q.front(); Q.pop();
			for (int dir = 0; dir < 6; dir++) {
				int nx = t.x + dx[dir];
				int ny = t.y + dy[dir];
				int nz = t.z + dz[dir];
				//printf("Q set: (%d %d %d)\n", nz, ny, nx);
				
				if ((nx < 0 or nx >= m) or (ny < 0 or ny >= n) or (nz < 0 or nz >= h))continue;
				//printf("xyz 범위오바안함\n");
				if (dist[nz][ny][nx] >= 0)continue;
				//printf("이미 방문안함\n");
				if( board[nz][ny][nx] < 0 ) continue;
				//printf("그림 1\n");
				dist[nz][ny][nx] = dist[t.z][t.y][t.x] + 1;
				Q.push(tomato(nz, ny, nx));
				
			}
		
		}

		time++;
	
	}

	bool clear = true;
		for (int a = 0; a < h; a++) {
			for (int b = 0; b < n; b++) {
				for(int c=0; c<m;c++)
				if (board[a][b][c] == 0) {
					if (dist[a][b][c] < 0) {
						clear = false;
						break;
					}
				}
			}
		}
		if (clear)
			printf("%d\n", time - 1);
		else
			printf("%d\n", -1);
}