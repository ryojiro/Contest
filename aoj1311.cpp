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
typedef pair<int, pi> pip;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

struct S {
	int id, del, cost;

	bool operator < (const S &a) const {
		return cost > a.cost;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, c;
	while(cin >> n >> m >> c, n|m|c) {
		vector< vector<pi> > vvp(101);
		bool closed[101][101] = {};
		REP(i, m) {
			int f, t, cst; cin >> f >> t >> cst;
			vvp[f].pb(pi(t, cst));
		}

		priority_queue<S> open;
		open.push(S{1, 0, 0});

		int ans = INF;
		while(!open.empty()) {
			S s = open.top(); open.pop();
			if(closed[s.id][s.del]) continue;
			closed[s.id][s.del] = true;

			if(s.id == n){
				ans = min(ans,s.del);
				continue;
			}

			REP(i, vvp[s.id].size()){
				pi e = vvp[s.id][i];
				if(s.cost + e.second <= c && !closed[e.first][s.del])
					open.push(S{e.first, s.del, s.cost + e.second});
				if(s.del < n && !closed[e.first][s.del+1]){
					open.push(S{e.first, s.del+1, s.cost});
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}
