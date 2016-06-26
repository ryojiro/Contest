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

int main() {
	int X, Y;
	while(cin >> X >> Y, X|Y) {
		bool b = true;
		int tx, ty, kx, ky, map[Y][X];
		cin >> tx >> ty >> kx >> ky;
		for(int i=0; i<Y; i++)
			for(int j=0; j<X; j++)
				cin >> map[i][j];

		queue<int> q;
		set<int> memo;

		q.push(0);
		q.push((tx-1)*1000000+(ty-1)*10000+(kx-1)*100+ky-1);

		while(q.size()) {
			int tx2, ty2, kx2, ky2, chk, cnt;
			cnt = q.front();
			q.pop();
			tx = q.front() /1000000;
			ty = q.front() /10000 %100;
			kx = q.front() /100 %100;
			ky = q.front() %100;
//			cout << q.front() << endl;

			if(tx == kx && ty == ky) {
				b = false;
				cout << cnt << endl;
				break;
			}
			if(cnt==100) {
				b = false;
				cout << "NA" << endl;
				break;
			}
			if(ty>0 && !map[ty-1][tx]) {
				ty--;
				if(ky<Y-1 && !map[ky+1][kx])
					ky++;
				chk = tx*1000000+ty*10000+kx*100+ky;
				if(memo.find(chk) == memo.end()) {
					memo.insert(chk);
					q.push(cnt+1);
					q.push(chk);
				}
				ty = q.front() /10000 %100;
				ky = q.front() %100;
			}
			if(tx>0 && !map[ty][tx-1]) {
				tx--;
				if(kx<X-1 && !map[ky][kx+1])
					kx++;
				chk = tx*1000000+ty*10000+kx*100+ky;
				if(memo.find(chk) == memo.end()) {
					memo.insert(chk);
					q.push(cnt+1);
					q.push(chk);
				}
				tx = q.front() /1000000;
				kx = q.front() /100 %100;
			}
			if(ty<Y-1 && !map[ty+1][tx]) {
				ty++;
				if(ky>0 && !map[ky-1][kx])
					ky--;
				chk = tx*1000000+ty*10000+kx*100+ky;
				if(memo.find(chk) == memo.end()) {
					memo.insert(chk);
					q.push(cnt+1);
					q.push(chk);
				}
				ty = q.front() /10000 %100;
				ky = q.front() %100;
			}
			if(tx<X-1 && !map[ty][tx+1]) {
				tx++;
				if(kx>0 && !map[ky][kx-1])
					kx--;
				chk = tx*1000000+ty*10000+kx*100+ky;
				if(memo.find(chk) == memo.end()) {
					memo.insert(chk);
					q.push(cnt+1);
					q.push(chk);
				}
				tx = q.front() /1000000;
				kx = q.front() /100 %100;
			}

			if(ky>0 && !map[ky-1][kx]) {
				ky--;
				if(ty<Y-1 && !map[ty+1][tx])
					ty++;
				chk = tx*1000000+ty*10000+kx*100+ky;
				if(memo.find(chk) == memo.end()) {
					memo.insert(chk);
					q.push(cnt+1);
					q.push(chk);
				}
				ty = q.front() /10000 %100;
				ky = q.front() %100;
			}
			if(kx>0 && !map[ky][kx-1]) {
				kx--;
				if(tx<X-1 && !map[ty][tx+1])
					tx++;
				chk = tx*1000000+ty*10000+kx*100+ky;
				if(memo.find(chk) == memo.end()) {
					memo.insert(chk);
					q.push(cnt+1);
					q.push(chk);
				}
				tx = q.front() /1000000;
				kx = q.front() /100 %100;
			}
			if(ky<Y-1 && !map[ky+1][kx]) {
				ky++;
				if(ty>0 && !map[ty-1][tx])
					ty--;
				chk = tx*1000000+ty*10000+kx*100+ky;
				if(memo.find(chk) == memo.end()) {
					memo.insert(chk);
					q.push(cnt+1);
					q.push(chk);
				}
				ty = q.front() /10000 %100;
				ky = q.front() %100;
			}
			if(kx<X-1 && !map[ky][kx+1]) {
				kx++;
				if(tx>0 && !map[ty][tx-1])
					tx--;
				chk = tx*1000000+ty*10000+kx*100+ky;
				if(memo.find(chk) == memo.end()) {
					memo.insert(chk);
					q.push(cnt+1);
					q.push(chk);
				}
				tx = q.front() /1000000;
				kx = q.front() /100 %100;
			}
			q.pop();
		}
		if(b) cout << "NA" << endl;
	}
	return 0;
}
