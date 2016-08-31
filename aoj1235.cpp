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
#include <complex>
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
#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for(int i = a; i < (int)b; i++)
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;
const int INF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {-1, -1, 0, 1, 1, 0}, dy[] = {0, -1, -1, 0, 1, 1};

int tri[10][10];
int n, c;

bool chk(int i, int j, bool b[10][10]) {
	if(i < 0 || j < 0 || n <= i || n <= j)
		return false;
	else if(tri[i][j] == -1 || b[i][j])
		return false;
	return true;
}

void dfs(int i, int j, int &cnt, bool b[10][10], bool &flg) {
	b[i][j] = true;
	REP(k, 6) {
		int y = i + dy[k], x = j + dx[k];
		if(chk(y, x, b)) {
			if(tri[y][x] == 0)
				flg = true;
			if(tri[i][j] == tri[y][x])
				dfs(y, x, ++cnt, b, flg);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> n >> c, n|c) {
		vector<pi> v;
		REP(i, 10) REP(j, 10)
			tri[i][j] = -1;
		REP(i, n) REP(j, i+1) {
			cin >> tri[i][j];
			if(tri[i][j] == 0)
				v.pb(mp(i, j));
		}

		int ans = -INF;
		REP(i, v.size()) {
			bool b[10][10] = {};
			tri[v[i].first][v[i].second] = c;
			int sum = 0, zero = 1;
			REP(j, 6) {
				int y = v[i].first + dy[j], x = v[i].second + dx[j];
				if(chk(y, x, b)) {
					if(tri[y][x] == 0 || tri[y][x] == c)
						zero = 0;
					if(tri[y][x]) {
						bool flg = false;
						int cnt = 1;
						dfs(y, x, cnt, b, flg);
						if(flg)
							continue;
						if(tri[y][x] == c)
							sum -= cnt;
						else
							sum += cnt;
					}
				}
			}
			ans = max(ans, sum - zero);
			tri[v[i].first][v[i].second] = 0;
		}
		cout << ans << endl;
	}
	return 0;
}
