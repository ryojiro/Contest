#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;


int main() {
	int W, H;
	cin >> W >> H;
	int field[H][W];

	char input;
	for(int i=0; i<H; i++) {
		for(int j=0; j<W; j++) {
			cin >> input;
			if(input == '#') field[i][j] = 10;
			else if(input == '.') field[i][j] = 100;
			else if(input == 'X') field[i][j] = 1000;
			else if(input == 'E') field[i][j] = 0;
			else if(input == 'N') field[i][j] = 1;
			else if(input == 'W') field[i][j] = 2;
			else if(input == 'S') field[i][j] = 3;
		}
	}

	queue<int> q;
	for(int i=0; i<H; i++) {
		for(int j=0; j<W; j++) {
			if(field[i][j] < 4) {
				q.push(H);
				q.push(W);
				q.push(field[i][j]);
			}
		}
	}

	int h, w, d;
	while(q.size() > 0) {
		//dicide direction
		int times = q.size()/3
		for(int j=0; j<times; j++) {
			h = q.pop();
			w = q.pop();
			d = q.pop();
			for(int i=0; i<4; i++) {
				if((d+i+3)%4 == 0) {
					if(w<W-1 && field[h][w+1] > 99) {
						q.push(h);
						q.push(w);
						q.push(0);
						break;
					}
				}
				else if((d+i+3)%4 == 1) {
					if(h>1 && field[h-1][w] > 99) {
						q.push(h);
						q.push(w);
						q.push(1);
						break;
					}
				}
				else if((d+i+3)%4 == 2) {
					if(w>1 && field[h][w-1] > 99) {
						q.push(h);
						q.push(w);
						q.push(2);
						break;
					}
				}
				else if((d+i+3)%4 == 3) {
					if(h<H-1 && field[h+1][w] > 99) {
						q.push(h);
						q.push(w);
						q.push(3);
						break;
					}
				}
			}
		}

		//dicide move
		for(int j=0; j<times; j++) {
			h = q.pop();
			w = q.pop();
			d = q.pop();
			if((d+i+3)%4 == 0) {
				if(w<W-1 && field[h][w+1] > 99) {
					d = 0;
					break;
				}
			}
			else if((d+i+3)%4 == 1) {
				if(h>1 && field[h-1][w] > 99) {
					d = 1;
					break;
				}
			}
			else if((d+i+3)%4 == 2) {
				if(w>1 && field[h][w-1] > 99) {
					d = 2;
					break;
				}
			}
			else if((d+i+3)%4 == 3) {
				if(h<H-1 && field[h+1][w] > 99) {
					d = 3;
					break;
				}
			}
		}


	return 0;
}
//MURI
