
////주석처리: Ctr + K + C
////주석해제 : Ctrl + K + U


//#include <iostream>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//#define _CRT_SECURE_NO_WARNINGS
//#define X first
//#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
//#define MAX 100000
//int dist[MAX]; // '1'이 파란 칸, '0'이 빨간 칸에 대응
//
//int main() {
//	
//	int N, K;
//	int time=0;
//	scanf(" %d %d",&N,&K);
//	dist[MAX] = { -1 };
//	bool run = false;
//	queue<int> Q;
//	Q.push(N);
//	dist[N] = 0;
//	while (!Q.empty()) {
//		auto cur = Q.front(); Q.pop();
//		 // 상하좌우 칸을 살펴볼 것이다.
//		for (int i = 0; i < 3; i++) {
//			int nx=0;
//			if(i==0)
//				 nx = cur - 1;
//			else if(i==1)
//				 nx = cur + 1;
//			else
//				 nx = cur*2;
//			printf("%d %d\n", nx, dist[nx]);
//			if (nx<0 or nx> MAX) continue; // 범위 밖일 경우 넘어감
//			printf("  범위");
//			if (dist[nx]>0 ) continue;
//			if (nx != N)
//			dist[nx] = dist[cur] + 1; // (nx, ny)의 거리는 현재 보고 있는 위치의 거리 + 1
//			printf(" 넣었나");
//			Q.push(nx);
//			printf(" Q에 넣음 : %d\n", nx);
//			if (nx == K) {
//				time = dist[nx];
//				run = true;
//				break;
//			}
//		}
//		if (run)
//			break;
//	}
//
//	printf("%d",time); // 문제의 특성상 거리+1이 정답
//}
//
//
