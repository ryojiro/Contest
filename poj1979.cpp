#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

char map[20][20];
int cnt;
int x, y;

void search(int sx, int sy) {
	map[sx][sy] = '0';
	cnt++;
	if(0 <= sx-1 && sx-1 < x && 0 <= sy && sy < y) {
		if(map[sx-1][sy] == '.') search(sx-1, sy);
	}
	if(0 <= sx && sx < x && 0 <= sy-1 && sy-1 < y) {
		if(map[sx][sy-1] == '.') search(sx, sy-1);
	}
	if(0 <= sx+1 && sx+1 < x && 0 <= sy && sy < y) {
		if(map[sx+1][sy] == '.') search(sx+1, sy);
	}
	if(0 <= sx && sx < x && 0 <= sy+1 && sy+1 < y) {
		if(map[sx][sy+1] == '.') search(sx, sy+1);
	}
} 

int main() {
	while(true) {
		cin >> x >> y;
		if(x==0 && y==0) break;
		int sx, sy;
		cnt = 0;
		for(int i=0; i<y; i++) {
			for(int j=0; j<x; j++) {
				cin >> map[j][i];
				if(map[j][i] == '@') {
					sx = j; sy = i;
				}
			}
		}
		search(sx, sy);
		cout << cnt << endl;
	}
	return 0;
}
