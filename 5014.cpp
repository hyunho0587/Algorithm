#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 1000000


int vist[MAX] = { 0 };
queue <int> Q;
int num = 0;


int main() {
	int F, S, G, U, D;
	bool clear= false;
	//Floor Start Goal Up Down
	scanf(" %d %d %d %d %d", &F, &S, &G, &U, &D);
		int move[2] = { U,D*(-1) };
		Q.push(S);
		vist[S] = 1;
		while (!Q.empty()) {
			if (Q.front() == G) {
				clear = true;
				break;
			}
			
			int size = Q.size();
			for (int i = 0; i < size; i++) {
				
				auto cur = Q.front();
				Q.pop();
				
				for (int j = 0; j < 2; j++)
				{
					int dx = cur + move[j];
					if (dx > F or dx <= 0) continue;
					if (vist[dx] == 1) continue;
					
					//printf("ÀÌµ¿: %d\n", dx);
					Q.push(dx);
					vist[dx] = 1;
					if (dx == G) {
						clear = true;
						break;
					}
				}
				//printf("++++++++++++++++++\n");
			}
			
				num++;
				//printf("%d\n",num);
				if (clear) { break; }	
		}//while

		if (clear) {
			printf("%d\n", num);
		}
		else {
			printf("use the stairs\n");
		}
}