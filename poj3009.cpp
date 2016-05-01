#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

int w, h;
int map[20][20];
int minim, sx, sy, gx, gy;

void route(int x, int y, int cnt, int dtn) {
	switch(dtn) {
		case 1: y--; break;
		case 2: x++; break;
		case 3: y++; break;
		case 4: x--; break;
	}

	if(x == gx && y == gy && cnt < minim) minim = cnt;
  cout << "hoge" << endl;

	if(map[x][y] != 1) {
	switch(dtn) {
		case 0:
			if(0 < y) route(x, y, 1, 1);
			if(x < w) route(x, y, 1, 2);
			if(y < h) route(x, y, 1, 3);
			if(0 < x) route(x, y, 1, 4);
			break;
		case 1:
			if(0 < y && map[x][y-1] == 0) route(x, y, cnt, 1);
			if(0 < y && map[x][y-1] == 1) {
				map[x][y-1] = 0;
				if(x < w) route(x, y, cnt++, 2);
				if(0 < x) route(x, y, cnt++, 4);
			}
			break;
		case 2:
			if(x < w && map[x+1][y] == 0) route(x, y, cnt, 2);
			if(x < w && map[x+1][y] == 1) {
				map[x+1][y] = 0;
				if(0 < x) route(x, y, cnt++, 1);
				if(y < h) route(x, y, cnt++, 3);
			}
			break;
		case 3:
			if(x < w && map[x][y+1] == 0) route(x, y, cnt, 3);
			if(x < w && map[x][y+1] == 1) {
				map[x][y+1] = 0;
				if(x < w) route(x, y, cnt++, 2);
				if(0 < x) route(x, y, cnt++, 4);
			}
			break;
		case 4:
			if(x < w && map[x-1][y] == 0) route(x, y, cnt, 4);
			if(x < w && map[x-1][y] == 1) {
				map[x-1][y] = 0;
				if(0 < x) route(x, y, cnt++, 1);
				if(y < h) route(x, y, cnt++, 3);
			}
			break;
	}
	}
}

int main() {
	while(true) {
		cin >> w >> h;
		if(w==0 && h==0) break;
		for(int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				cin >> map[i][j];
				if(map[i][j] == 2) { sx = j; sy = i;}
				if(map[i][j] == 3) { gx = j; gy = i;}
			}
		}
		minim = 50000;
		route(sx, sy, 1, 0);
		if(minim == 50000) cout << -1 << endl;
		else cout << minim << endl;
	}

	return 0;
}
