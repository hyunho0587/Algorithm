#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#define X first
#define Y second
#define MAX 100

using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
char board[MAX][MAX] = {0};


char color_set[3] = { 'R','G','B' };

int main() {
	queue<pair<int, int>> Q;
	vector<int> V;
	bool check = false;
	int N;
	int color_num=0;
	scanf(" %d",&N);
	for (int i = 0; i < N; i++) {
		scanf(" %s", board[i]);
	}
	for (int color = 0; color < 4; color++) { // color => 0-R / 1-G / 2-B / 3-RG
		int dist[MAX][MAX] = { 0 };
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
		
				if (color == 3 && dist[i][j] ==0) {
					if (board[i][j] == 'R' or board[i][j] == 'G') {
						Q.push({ i,j });
						dist[i][j] = 1;
						//printf("RG start : (%d, %d)\n", i, j);
						check = true;
					}
				}
				else {
					if (dist[i][j] == 0)
					{
						if (board[i][j] == color_set[color]) {
							Q.push({ i,j });
							dist[i][j] = 1;
							//printf("%c start : (%d, %d)\n", color_set[color], i, j);
							check = true;
						}
					}
				}
				
				while (!Q.empty()) {
					int Qsize = Q.size();
					for (int k = 0; k < Q.size(); k++) {
						auto cur = Q.front(); Q.pop();

						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];

							if (dist[nx][ny] == 1)continue;
							if (nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
							
							if (color == 3) {
								if (board[nx][ny] == 'R' or board[nx][ny] == 'G') {
									Q.push({ nx,ny });
									dist[nx][ny] = 1;
									//printf("RG : (%d, %d)\n", nx, ny);
								}
							}
							else {
								if (board[nx][ny] == color_set[color]) {
									Q.push({ nx,ny });
									dist[nx][ny] = 1;
									//printf("%c : (%d, %d)\n",color_set[color], nx, ny);
								}
							}

						}
					}
				}
				if (check) {
					color_num++;
					//printf("color_num : %d\n", color_num);
				}
				check = false;
			}
		}
		V.push_back(color_num);
		color_num = 0;
		
	}
	int not_RG=0;
	int RG=0;
	not_RG = V[0] + V[1] + V[2];
	RG = V[2] + V[3];
	printf("%d %d\n",not_RG, RG);
	
}