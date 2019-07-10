//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//#define X first
//#define Y second // pair���� first, second�� �ٿ��� ���� ���ؼ� ���
//#define MAX 1000
//
//int dist[MAX][MAX]; // �ش� ĭ�� �湮�ߴ��� ���θ� ����
//int n, m;
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 }; // �����¿� �� ������ �ǹ�
//int board[MAX][MAX];
//
//int main() {
//	int time = 0;
//	scanf(" %d %d", &m, &n);
//	queue<pair<int, int>> Q;
//	for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			scanf(" %d", &board[i][j]);
//			if (board[i][j] == 1) {
//				Q.push({ i,j });//���� ��� �ֱ�
//				dist[i][j] = 0;
//			}
//		}
//	}//����
//
//	while (!Q.empty()) {
//		int size = Q.size();
//		for (int i = 0; i < size; i++) {
//			auto cur = Q.front(); Q.pop();
//			for (int dir = 0; dir < 4; dir++) {
//				int nx = cur.X + dx[dir];
//				int ny = cur.Y + dy[dir];
//				if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;				
//				if (dist[nx][ny] >= 0 or board[nx][ny] < 0) continue;
//
//				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
//				Q.push({ nx,ny });
//				printf("%d %d\n",nx,ny);
//			}
//		}
//		time++;
//
//		
//	}
//
//	bool clear = true;
//	for (int a = 0; a < n; a++) {
//		for (int b = 0; b < m; b++) {
//			if (board[a][b] == 0) {
//				if (dist[a][b] < 0) {
//
//					clear = false;
//					break;
//				}
//			}
//		}
//	}
//	if (clear)
//		printf("%d\n", time - 1);
//	else
//		printf("%d\n", -1);
//}