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

struct team {
	int no, ac, wa[10], time;
	bool operator < (const team& a) const {
		if(ac == a.ac) {
			if(time == a.time)
				return no > a.no;
			else
				return time < a.time;
		}
		else
			return ac > a.ac;
	}
};

int main() {
	int M, T, P, R;
	while(cin >> M >> T >> P >> R, M|T|P|R) {
		vector<team> vt;
		REP(i, T) {
			team t;
			t.no = i + 1;
			t.ac = t.time = 0;
			memset(t.wa, 0, sizeof(t.wa));
			vt.push_back(t);
		}
		REP(i, R) {
			int m, t, p, j;
			cin >> m >> t >> p >> j;
			if(j)
				vt[t-1].wa[p-1]++;
			else {
				vt[t-1].ac++;
				vt[t-1].time += m + vt[t-1].wa[p-1] * 20;
			}
		}
		sort(vt.begin(), vt.end());
		int a = vt[0].ac, t = vt[0].time;
		cout << vt[0].no;
		FOR(i, 1, vt.size()) {
			if(vt[i].ac == a && vt[i].time == t)
				cout << '=';
			else {
				a = vt[i].ac;
				t = vt[i].time;
				cout << ',';
			}
			cout << vt[i].no;
		}
		cout << endl;
//		REP(i, vt.size()) cout << vt[i].no << ' ' << vt[i].ac << ' ' << vt[i].time << endl;
	}
	return 0;
}
