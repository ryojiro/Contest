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

int w, h;
struct

bool chk(int x, int y) {
	if(x < 0 || y < 0 || h-1 < x || w-1 < y)
		return false;
	return true;
}

void dfs(int x, int y, bool d[h][w]) {
	REP(i, 4) {
		int x2 = x + dx[i], y2 = y + dy[i];
		if(chk(x2, y2) && !d[x2][y2]) {
			b[x2][y2] = 5;
			dfs(x + dx[i], y + dy[i], d);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> w >> h, w|h) {
		int d[h][w];
		pi p;
		REP(i, h) REP(j, w) {
			cin >> d[i][j];
			if(d[i][j] == 4) {
				p = mp(i, j);
				d[i][j] = 0;
			}
		}
		dfs(p.first, p.second, d);






	return 0;
}
