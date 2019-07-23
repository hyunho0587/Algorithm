#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
#define x first
#define y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
#define max 100

int dist[max][max] = { 0 }; // 해당 칸을 방문했는지 여부를 저장

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미
int board[max][max] = { 0 };

int main() {
	int n,m,k;
	int rx, ry, lx, ly;
	int square_num=0;
	int square_size=0;
	queue<pair<int, int>> q;
	vector<int> v;
	scanf(" %d %d %d", &m,&n,&k);//board 크기
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d %d", &lx, &ly, &rx, &ry);
		for (int j = lx; j < rx; j++) {
			for (int a = ly; a < ry; a++) {
				board[a][j] = 2;
				printf("(%d,%d)\n",a,j);
			}
		}//그림 그리기
	}
		for (int b = 0; b < m; b++) {
			for (int c = 0; c < n; c++) {
				if (board[b][c] != 2 && dist[b][c]!=1) {
					q.push({ b,c });
					printf("start: %d %d\n", b, c);
					dist[b][c] = 1;
					square_num++;
					
				}
				while (!q.empty()) {
					for (int d = 0; d < q.size(); d++) {
						auto cur = q.front(); q.pop();
						square_size++;
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.x + dx[dir];
							int ny = cur.y + dy[dir];
							if (board[nx][ny] == 2) continue;
							if (nx < 0 or nx >= m or ny < 0 or ny >= n) continue;
							if (dist[nx][ny] == 1) continue;

							q.push({ nx,ny });
							printf("push: %d %d\n", nx, ny);
							dist[nx][ny] = 1;
							

						}
					}
				}
				//square size 끝
				if (square_size > 0) {
					v.push_back(square_size);
				}
				square_size = 0;
			}
		}
	
	printf("result : %d\n",square_num);
	sort(v.begin(), v.end());
	for (int g = 0; g < v.size(); g++) {
		printf("%d ",v[g]);
	}
	
}