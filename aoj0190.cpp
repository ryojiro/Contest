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
#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for(int i = a; i < (int)b; i++)
const int INF = 1<<28;
int pnt[11][2] = {
	{1,1}, {1,2}, {1,3}, {2,0},
	{2,1}, {2,2}, {2,3}, {2,4},
	{3,1}, {3,2}, {3,3}
};
int ans = -1;
struct F {
	int p[5][5];
	int cnt;
};
set<string> s;
queue<F> q;

bool cost(int p[5][5], int cnt) {
	int c = cnt;
	REP(i, 5) REP(j, 5) {
		if(p[i][j] > 0) {
			c += abs(i - pnt[p[i][j]-1][0]);
			c += abs(j - pnt[p[i][j]-1][1]);
//			cout << abs(i - pnt[p[i][j]-1][0]) << ' ' << abs(j - pnt[p[i][j]-1][1]) << "  ";
		}
	}
//	cout << c << endl;
	if(c == cnt) ans = cnt;
	return (c > 20) ? true : false;
}

void bfs() {
	while(q.size()) {
		F f = q.front();
		q.pop();
//		cout << cost(f.p, f.cnt) << endl;
		if(cost(f.p, f.cnt)) continue;
		if(ans != -1) break;
		string str = "";
		REP(i, 5) REP(j, 5) str += to_string(f.p[i][j]) + ',';
		if(s.count(str) > 0) continue;
//		cout << str << endl;
		s.insert(str);
		REP(i, 5) REP(j, 5) {
			if(f.p[i][j] == 0) {
				if(j < 4 && f.p[i][j+1] != -1) {
					F f2 = f;
					swap(f2.p[i][j], f2.p[i][j+1]);
					f2.cnt++;
					q.push(f2);
				}
				if(0 < j && f.p[i][j-1] != -1) {
					F f2 = f;
					swap(f2.p[i][j], f2.p[i][j-1]);
					f2.cnt++;
					q.push(f2);
				}
				if(i < 4 && f.p[i+1][j] != -1) {
					F f2 = f;
					swap(f2.p[i][j], f2.p[i+1][j]);
					f2.cnt++;
					q.push(f2);
				}
				if(0 < i && f.p[i-1][j] != -1) {
					F f2 = f;
					swap(f2.p[i][j], f2.p[i-1][j]);
					f2.cnt++;
					q.push(f2);
				}
			}
		}
	}
	return;
}

int main() {
	while(true) {
		q = queue<F>();
		s.clear();
		ans = -1;
		F f;
		int p[5][5] = {
			{-1, -1, 0, -1, -1},
			{-1, 0, 0, 0, -1},
			{0, 0, 0, 0, 0},
			{-1, 0, 0, 0, -1},
			{-1, -1, 0, -1, -1},
		};
		REP(i, 5) REP(j, 5) {
			if(p[i][j] == -1) {
				f.p[i][j] = -1;
				continue;
			}
			else
				cin >> f.p[i][j];
			if(f.p[i][j] == -1) return 0;
		}
		f.cnt = 0;
		q.push(f);
		bfs();
		if(ans < 0) cout << "NA" << endl;
		else cout << ans << endl;
	}
	return 0;
}
