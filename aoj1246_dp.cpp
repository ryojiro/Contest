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
#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for(int i = a; i < (int)b; i++)
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
const int IINF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

struct Period {
	int i, j, w;
	bool operator < (const Period &p) const {
		return i == p.i ? j < p.j : i < p.i; 
	}
};

int n;
int dp[365 + 1][365 + 1];
Period period[1000];

int main() {
	ios::sync_with_stdio(false);

	while(cin >> n && n) {
		Period p;
		REP(i, n) {
			cin >> p.i >> p.j >> p.w;
			period[i] = p;
		}

		sort(period, period + n);
		memset(dp, 0, sizeof(dp));

		REP(i, n) {
			p = period[i];
			for(int k = 365; k >= 0; k--) {
				for(int j = p.i - 1; j >= 0; j--) {
					dp[k][p.j] = max(dp[k][p.j], dp[k][j] + p.w);
					dp[p.j][k] = max(dp[p.j][k], dp[j][k] + p.w);
				}
			}
		}

		int ans = 0;
		REP(i, 366) REP(j, 366)
			ans = max(ans, dp[i][j]);

		cout << ans << endl;
		REP(i, 10) {
			REP(j, 10)
				cout << dp[i][j] << ' ';
			cout << endl;
		}
	}

	return 0;
}
