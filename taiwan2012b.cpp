#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
using namespace std;
#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); i++)
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0, -1}, dy[] = {0, 1, 0, -1, -1};

bool chk(int x, int y) {
	if(x < 0 || y < 0 || 2 < x || 2 < y)
		return false;
	return true;
}

struct S {
	vector<vi> fld;
	int cnt;
	pi pnt;
};

void dfs(S s, queue<S> &q, set<vector<vi> > &mem, int x, int y) {
	int _x = s.pnt.first + x, _y = s.pnt.second + y;
	if(!chk(_x, _y)) return;

	swap(s.fld[s.pnt.first][s.pnt.second], s.fld[_x][_y]);
	s.cnt++;
	s.pnt = pi(_x, _y);
	if(!mem.count(s.fld)) {
		mem.insert(s.fld);
		q.push(s);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	while(n--) {
		vector<vi> fld(3), ans(3);
		set<vector<vi> > mem;
		pi pnt;
		REP(i, 3) {
			fld[i].resize(3);
			REP(j, 3) {
				cin >> fld[i][j];
				if(fld[i][j] == 0)
					pnt = pi(i,j);
			}
		}
		REP(i, 3) {
			ans[i].resize(3);
			REP(j, 3)
				cin >> ans[i][j];
		}
		queue<S> q;
		q.push(S{fld, 0, pnt});
		bool flg = false;
		while(q.size()) {
			S s = q.front(); q.pop();
			if(q.front().fld == ans) {
				flg = true;
				break;
			}
			REP(i, 5) {
				dfs(s, q, mem, dx[i], dy[i]);
	//			cout << s.pnt.first << ' ' << s.pnt.second << endl;
			}
		}
		cout << (flg ? q.front().cnt : -1) << endl;
	}
	return 0;
}
