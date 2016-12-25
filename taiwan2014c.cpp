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
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

pi ans;
set<set<pi> > memo;

bool chk(int x, int y, int n) {
	if(x < 0 || y < 0 || n <= x || n <= y)
		return false;
	return true;
}

void mv(int x, int y, int n, set<pi> &s) {
	int _x = x, _y = y;
	while(chk(_x, _y, n)) {
		s.insert(pi(_x, _y));
		_x++;
	}
	_x = x, _y = y;
	while(chk(_x, _y, n)) {
		s.insert(pi(_x, _y));
		_x--;
	}
	_x = x, _y = y;
	while(chk(_x, _y, n)) {
		s.insert(pi(_x, _y));
		_y--;
	}
	_x = x, _y = y;
	while(chk(_x, _y, n)) {
		s.insert(pi(_x, _y));
		_y++;
	}

	_x = x, _y = y;
	while(chk(_x, _y, n)) {
		s.insert(pi(_x, _y));
		_x++; _y++;
	}
	_x = x, _y = y;
	while(chk(_x, _y, n)) {
		s.insert(pi(_x, _y));
		_x++; _y--;
	}
	_x = x, _y = y;
	while(chk(_x, _y, n)) {
		s.insert(pi(_x, _y));
		_x--; _y++;
	}
	_x = x, _y = y;
	while(chk(_x, _y, n)) {
		s.insert(pi(_x, _y));
		_x--; _y--;
	}

	_x = x, _y = y;
	while(chk(_x, _y, n)) {
		s.insert(pi(_x, _y));
		_y += 2; _x++;
	}
	_x = x, _y = y;
	while(chk(_x, _y, n)) {
		s.insert(pi(_x, _y));
		_y += 2; _x--;
	}
	_x = x, _y = y;
	while(chk(_x, _y, n)) {
		s.insert(pi(_x, _y));
		_x += 2; _y++;
	}
	_x = x, _y = y;
	while(chk(_x, _y, n)) {
		s.insert(pi(_x, _y));
		_x += 2; _y--;
	}

	_x = x, _y = y;
	while(chk(_x, _y, n)) {
		s.insert(pi(_x, _y));
		_y -= 2; _x++;
	}
	_x = x, _y = y;
	while(chk(_x, _y, n)) {
		s.insert(pi(_x, _y));
		_y -= 2; _x--;
	}
	_x = x, _y = y;
	while(chk(_x, _y, n)) {
		s.insert(pi(_x, _y));
		_x -= 2; _y++;
	}
	_x = x, _y = y;
	while(chk(_x, _y, n)) {
		s.insert(pi(_x, _y));
		_x -= 2; _y--;
	}

	return;
}

void dfs(int n, set<pi> s, int cnt, set<pi> put) {
	bool flg = false;
	REP(i, n) REP(j, n) {
		if(!s.count(pi(i,j))) {
			flg = true;
			set<pi> _s = s;
			mv(i, j, n, _s);
			put.insert(pi(i,j));
			dfs(n, _s, cnt+1, put);
			put.erase(pi(i,j));
		}
	}
	if(!flg) {
		if(memo.count(put))
			return;
		else
			memo.insert(put);

		if(ans.first < cnt)
			ans = pi(cnt, 1);
		else if(ans.first == cnt)
			ans.second++;
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	while(N--) {
		ans = pi(0, 0);
		memo.clear();

		int n, ps; cin >> n >> ps;
		set<pi> s;
		REP(i, ps) {
			int x, y; cin >> x >> y;
			mv(x, y, n, s);
		}
		dfs(n, s, 0, set<pi>());
		cout << ans.first + ps << ' ' << ans.second << endl;
	}

	return 0;
}
