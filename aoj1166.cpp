#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <cstring>
#include <cctype>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <complex>
using namespace std;

int field[30][30];
int hor[30][30];
int ver[30][30];
int result;
int w, h;


int main() {
	while(1) {
		cin >> w >> h;
		if(w==0 && h==0) break;

		for(int i=0; i<h; i++)
			for(int j=0; j<w; j++)
				field[i][j] = 0;

		for(int i=0; i<h*2-1; i++) {
			if(i%2==0) {
				for(int j=0; j<w-1; j++) {
					cin >> ver[i/2][j];
				}
			}
			else {
				for(int j=0; j<w; j++) {
					cin >> hor[i/2][j];
				}
			}
		}

		queue<int> q;
		q.push(0);
		q.push(0);
		q.push(1);
		result = 0;

		while(q.size() != 0) {
			int x = q.front();
			q.pop();
			int y = q.front();
			q.pop();
			int cnt = q.front();
			q.pop();

			if(field[y][x] == 1) continue;

			if(x == w-1 && y == h-1) {
				result = cnt;
				break;
			}

			if(y<h-1 && hor[y][x] == 0) {
				q.push(x);
				q.push(y+1);
				q.push(cnt+1);
			}
			if(x<w-1 && ver[y][x] == 0) {
				q.push(x+1);
				q.push(y);
				q.push(cnt+1);
			}
			if(y>0 && hor[y-1][x] == 0) {
				q.push(x);
				q.push(y-1);
				q.push(cnt+1);
			}
			if(x>0 && ver[y][x-1] == 0) {
				q.push(x-1);
				q.push(y);
				q.push(cnt+1);
			}
			field[y][x] = 1;
		}
		cout << result << endl;
	}
	return 0;
}
