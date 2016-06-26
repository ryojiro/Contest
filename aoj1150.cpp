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
const int INF = 1<<28;

struct feet {
	int x, y, p, cnt;
	feet(int a, int b, int c, int d): x(a), y(b), p(c), cnt(d) {};
	bool operator >(feet const &a) const {
		return cnt > a.cnt;
	}
};

int main() {
	int w, h;
	int x[9] = {1, 1, 1, 1, 1, 2, 2, 2, 3};
	int y[9] = {2, 1, 0, -1, -2, 1, 0, -1, 0};
	while(cin >> w >> h, w|h) {
		priority_queue<feet, vector<feet>, greater<feet> > pq;
		map<int, int> memo;
		set<int> t;

		int field[h][w];
		for(int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				char input;
				cin >> input;
				if((int)input - '0' < 10)
					field[i][j] = (int)input - '0';
				else if(input == 'X') 
					field[i][j] = INF;
				else if(input == 'S') {
					field[i][j] = 0;
					pq.push(feet(j, i, 0, 0));
					pq.push(feet(j, i, 1, 0));
				}
				else if(input == 'T') {
					field[i][j] = 0;
					t.insert(j*100+i);
				}
			}
		}

		int ans = INF;

		while(pq.size()) {
			feet f = pq.top();
			pq.pop();

			if(t.count(f.x*100+f.y)) { // 'T'
				ans = ans>f.cnt ? f.cnt : ans;
				continue;
			}

			for(int i=0; i<9; i++) {
				feet temp(f.x+x[i], f.y+y[i], !f.p, f.cnt+field[f.y+y[i]][f.x+x[i]]);
				if(f.p) {
					temp.x = f.x-x[i];
					temp.cnt = f.cnt+field[f.y+y[i]][f.x-x[i]];
				}
				int chk = temp.x*10000 + temp.y*100 + temp.p;
				if(field[temp.y][temp.x] != INF) { // 'x'
					if(0 <= temp.x && temp.x < w && 0 <= temp.y && temp.y < h) { //out of range
						if(memo.find(chk) == memo.end() || memo[chk] > temp.cnt) {
							memo[chk] = temp.cnt;
							pq.push(temp);
						}
					}
				}
			}
		}
		cout << (ans==INF ? -1 : ans) << endl;
	}
	return 0;
}
