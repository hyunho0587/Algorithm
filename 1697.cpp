
////�ּ�ó��: Ctr + K + C
////�ּ����� : Ctrl + K + U


//#include <iostream>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//#define _CRT_SECURE_NO_WARNINGS
//#define X first
//#define Y second // pair���� first, second�� �ٿ��� ���� ���ؼ� ���
//#define MAX 100000
//int dist[MAX]; // '1'�� �Ķ� ĭ, '0'�� ���� ĭ�� ����
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
//		 // �����¿� ĭ�� ���캼 ���̴�.
//		for (int i = 0; i < 3; i++) {
//			int nx=0;
//			if(i==0)
//				 nx = cur - 1;
//			else if(i==1)
//				 nx = cur + 1;
//			else
//				 nx = cur*2;
//			printf("%d %d\n", nx, dist[nx]);
//			if (nx<0 or nx> MAX) continue; // ���� ���� ��� �Ѿ
//			printf("  ����");
//			if (dist[nx]>0 ) continue;
//			if (nx != N)
//			dist[nx] = dist[cur] + 1; // (nx, ny)�� �Ÿ��� ���� ���� �ִ� ��ġ�� �Ÿ� + 1
//			printf(" �־���");
//			Q.push(nx);
//			printf(" Q�� ���� : %d\n", nx);
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
//	printf("%d",time); // ������ Ư���� �Ÿ�+1�� ����
//}
//
//
