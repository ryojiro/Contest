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
vector<pi> x;
int n, ans;

void dfs(int pnt, int cnt, bool b[5][200]) {
	if(pnt + n > ans) return;
	if(cnt == 10) {
		ans = min(ans, pnt + n-1);
		return;
	}
	REP(i, x.size()) {
		if(b[x[i].first][x[i].second + pnt]) {
			dfs(pnt+1, cnt, b);
			return;
		}
	}
	REP(i, x.size())
		b[x[i].first][x[i].second + pnt] = true;
	dfs(pnt+1, cnt+1, b);
	REP(i, x.size())
		b[x[i].first][x[i].second + pnt] = false;
	dfs(pnt+1, cnt, b);
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> n, n) {
		ans = n * 10;
		x.clear();
		REP(i, 5) REP(j, n) {
			char c; cin >> c;
			if(c == 'X')
				x.pb(mp(i, j));
		}
		bool b[5][200] = {};
		dfs(0, 0, b);
		cout << ans << endl;
	}
	return 0;
}
