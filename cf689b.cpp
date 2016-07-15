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
#include <queue>
#include <complex>
using namespace std;
#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for(int i = a; i < (int)b; i++)
const int INF = 1<<28;

int n, in[200001], dp[200001];

void solve(int m) {
	if(dp[m] + 1 < dp[in[m]]) {
		dp[in[m]] = dp[m] + 1;
		solve(in[m]);
	}
	if(1 < m && dp[m] + 1 < dp[m-1]) {
		dp[m-1] = dp[m] + 1;
		solve(m-1);
	}
	if(m < n && dp[m] + 1 < dp[m+1]) {
		dp[m+1] = dp[m] + 1;
		solve(m+1);
	}
	return;
}

int main() {
	cin >> n;
	FOR(i, 1, n+1) {
		cin >> in[i];
	}
	fill(dp, dp+n+1, INF);
	dp[1] = 0;
	solve(1);

	FOR(i, 1, n+1)
		cout << dp[i] <<  ' ';
	cout << endl;

	return 0;
}
