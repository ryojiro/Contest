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
const int IINF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

struct S {
	int x, y, g;

	bool operator < (const S &a) const {
		return g < a.g;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		char m[n][n];
		vector<S> vs;
		REP(i, n) REP(j, n) {
			cin >> m[i][j];
			if(isdigit(m[i][j]))
				vs.pb(S{j, i, m[i][j] - '0'});
		}

		vi rnd;
		REP(i, n-1) rnd.pb(m[i][0]);
		REP(i, n-1) rnd.pb(m[n-1][i]);
		for(int i=n-1; i > 0; i--) rnd.pb(m[i][n-1]);
		for(int i=n-1; i > 0; i--) rnd.pb(m[0][i]);

		int chk = 0;
		bool b = false;
		REP(i, rnd.size()) {
			if(isdigit(rnd[i])) {
				if(chk == rnd[i]) b = true;
				chk = rnd[i];
			}
		}
		if(!b) {
			cout << -1 << endl;
			continue;
		}
		int sum = 2;
		bool x2 = false, y2 = false;
		FOR(i, 1, vs.size()) {
			if(vs[i-1].x != vs[i].x)
				x2 = true;
			if(vs[i-1].y != vs[i].y)
				y2 = true;
		}
		if((!x2 && vs[0].x != vs[1].x) || (!y2 && vs[0].y != vs[1].y)) sum += 2;

		sort(vs.begin(), vs.end());
		sum += abs(vs[0].x - vs[1].x);
		sum += abs(vs[0].y - vs[1].y);
		sum += abs(vs[2].x - vs[3].x);
		sum += abs(vs[2].y - vs[3].y);

		cout << sum << endl;

	}
	return 0;
}
