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
#include <stack>
#include <queue>
#include <complex>
using namespace std;
#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for(int i = a; i < (int)b; i++)
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;
const int INF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

struct s {
	int px, py, cx, cy, cnt;
	s() {};
	s(int a, int b, int c, int d, int e) : px(a), py(b), cx(c), cy(d), cnt(e) {};
};

int w, h;
set<int> memo;
bool done[7][7]; //探索メモ
bool b[7][7]; //人がいけるところ
int m[7][7]; //マップ

bool chk(int y, int x) {
	if(x < 0 || y < 0 || h-1 < y || w-1 < x)
		return false;
	return true;
}

void dfs(int y, int x, int cy, int cx) {
	REP(i, 4) {
		int x2 = x + dx[i], y2 = y + dy[i];
		if(chk(y2, x2) && !done[y2][x2]) {
			if(m[y2][x2] == 0 || m[y2][x2] == 3) {
				if(cy == y && cx == x)
					return;
				done[y2][x2] = true;
				b[y2][x2] = true;
				dfs(y2, x2, cy, cx);
			}
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> w >> h, w|h) {
		queue<s> q;
		s a;
		memset(m, false, sizeof(m));
		memo.clear();
		REP(i, h) {
			REP(j, w) {
				cin >> m[i][j];
				if(m[i][j] == 4) {
					a.py = i; a.px = j;
					m[i][j] = 0;
				}
				if(m[i][j] == 2) {
					a.cy = i; a.cx = j;
					m[i][j] = 0;
				}
			}
		}
		q.push(a);

		int ans = -1;
		while(q.size()) {
			s a = q.front(); q.pop();

			memset(done, false, sizeof(done));
			memset(b, false, sizeof(b));
			b[a.py][a.px] = true;
			dfs(a.py, a.px, a.cy, a.cx);

			bool flg = false;
			REP(i, 4) {
				int cx2 = a.cx + dx[i], cy2 = a.cy + dy[i];
				int cx3 = a.cx + dx[(i+2)%4], cy3 = a.cy + dy[(i+2)%4];
				int d = cx2 * 1000 + cy2 * 100 + cx3 * 10 + cy3;
				if(!chk(cy2, cx2) || !chk(cy3, cx3))
					continue;
				if(b[cy2][cx2] && (m[cy3][cx3] == 0 || m[cy3][cx3] == 3) && !memo.count(d)) {
					if(m[cy3][cx3] == 3) {
						ans = a.cnt + 1;
						flg = true;
					}
					q.push(s(a.cx, a.cy, cx3, cy3, a.cnt + 1));
					memo.insert(d);
				}
			}
			if(flg) break;
		}
		cout << ans << endl;
	}
	return 0;
}
