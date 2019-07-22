#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
#define MAX 25

int dist[MAX][MAX] = {0}; // 해당 칸을 방문했는지 여부를 저장

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미
char board[MAX][MAX] = {'0'};

int main() {
	int N;
	string m;
	int house_kind = 0;
	int house_num=0;
	queue<pair<int, int>> Q;
	vector<int> V;
	scanf(" %d", &N);//board 크기

	for (int i = 0; i < N; i++) {
		scanf(" %s", board[i]);
		
		
	
	}//그림 입력
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == '1' && dist[i][j] == 0) {
				Q.push({ i,j });
				printf("start: (%d, %d)\n", i, j);
				dist[i][j] = 1;
				
				house_kind++;
				house_num++;
			}


			while (!Q.empty()) {
				
				for (int a = 0; a < Q.size(); a++) {

					auto cur = Q.front(); Q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = dx[k] + cur.X;
						int ny = dy[k] + cur.Y;

						if (dist[nx][ny] == 1) continue;
						if (board[nx][ny] == '0') continue;
						if (nx < 0 or nx >= N or ny < 0 or ny >= N) continue;

						Q.push({ nx,ny });
						printf("push(%d, %d)\n",nx,ny);
						house_num++;
						dist[nx][ny] = 1;

					}
				}
			}
			
			if (house_num >0) { 
				printf("vector push\n");
				V.push_back(house_num); 
				house_num = 0;
			}
			
		}
	}
	sort(V.begin(), V.end());
	printf("kind : %d\n", house_kind);
	for (int b = 0; b < V.size(); b++) {
		printf("%d\n", V[b]);
	}
}