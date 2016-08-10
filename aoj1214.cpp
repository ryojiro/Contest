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
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int ans;
int f[8][8];
int w, h;
struct p {
	int x, y, cnt, stv;
	p(int a, int b, int c, int d) : x(a), y(b), cnt(c), stv(d) {}
};
int chk(int x, int y, bool b[8][8]) {
	if(b[x][y])
		return 0;
	else if(x < 0 || y < 0 || h-1 < x || w-1 < y)
		return 0;
	else {
		b[x][y] = true;
		return f[x][y];
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> w >> h, w|h) {
		queue<p> start, search;
		REP(i, h) REP(j, w) {
			cin >> f[i][j];
			if(f[i][j] == 2) {
				start.push(p(i, j, 0, 5));
				f[i][j] = 1;
			}
		}

		int ans = -1;
		bool flg = false;
		set<pi> s;
		while(start.size()) {
			search.push(start.front());
			start.pop();
			while(search.size()) {
				p p2 = search.front();
				search.pop();
				if(p2.stv == 0)
					continue;
				bool b[8][8] = {};
				b[p2.x][p2.y] = true;
				REP(i, 4) {
					int res = chk(p2.x + dx[i], p2.y + dy[i], b);
					if(res > 0)
						search.push(p(p2.x + dx[i], p2.y + dy[i], p2.cnt + 1, p2.stv - 1));
					if(res == 3) {
						ans = p2.cnt + 1;
						flg = true;
					}
					if(res == 4) {
						if(!s.count(mp(p2.x + dx[i],  p2.y + dy[i]))) {
							s.insert(mp(p2.x + dx[i],  p2.y + dy[i]));
							start.push(p(p2.x + dx[i], p2.y + dy[i], p2.cnt + 1, 5));
						}
					}
				}
				if(flg) break;
			}
			if(flg) break;
		}
		cout << ans << endl;
	}
	return 0;
}
