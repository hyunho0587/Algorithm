#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define MAX 600000

int main() {

	vector<char> myvector;
	vector<char>::iterator cursor;
	
	int test = 0;
	char str[MAX];
	char con[1];
	char input_text[1];
	scanf(" %s", str);
	int len = strlen(str);
	for (int a = 0; a < len; a++) {
		myvector.push_back(str[a]);
	}
	cursor = myvector.end() ;
	scanf("%d",&test);
	for (int i = 0; i < test; i++) {
		scanf("%s",&con);
		if (strcmp(con, " L")) {
			scanf("%s",&input_text);
			myvector.insert(cursor-1,input_text[0]);
		}
		else if (strcmp(con,"L")) {
			if(cursor > myvector.begin())
				cursor - 1;
		}
		else if (strcmp(con, "R")) {
			if (cursor < myvector.end())
				cursor + 1;
		}
		else if (strcmp(con, "B")){
			if (cursor <= myvector.end() + 1)
				myvector.erase(cursor);
		}
	}
	for (int v = 0; v < myvector.size(); v++) {
		printf("%c",myvector[v]);
	}
	
	
}