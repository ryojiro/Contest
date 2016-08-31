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
const ll INF = 1e18;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<ll> c(n);
	vector<string> s(n), rs(n);
	REP(i, n)
		cin >> c[i];
	REP(i, n) {
		cin >> s[i];
		rs[i] = s[i];
		reverse(rs[i].begin(), rs[i].end());
	}
	ll dp[2][100001] = {};
	fill(dp[0], dp[0]+n, INF);
	fill(dp[1], dp[1]+n, INF);
	dp[0][0] = 0;
	dp[1][0] = c[0];

	bool flg = false;
	FOR(i, 1, n) {
		if(s[i-1] <= s[i])
			dp[0][i] = min(dp[0][i], dp[0][i-1]);
		if(rs[i-1] <= s[i])
			dp[0][i] = min(dp[0][i], dp[1][i-1]);
		if(s[i-1] <= rs[i])
			dp[1][i] = min(dp[1][i], dp[0][i-1] + c[i]);
		if(rs[i-1] <= rs[i])
			dp[1][i] = min(dp[1][i], dp[1][i-1] + c[i]);
		if(dp[0][i] == INF && dp[1][i] == INF)
			flg = true;
	}
//	REP(i, n)
//		cout << i << ' ' << dp[0][i] << ' ' << dp[1][i] << endl;
	ll ans = min(dp[0][n-1], dp[1][n-1]);
	cout << (flg ? -1 : ans) << endl;
	return 0;
}
