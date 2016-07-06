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

int dp[1401][1401], in[1401][1401];

int solve(int H, int W) {
	int width = 0;

	REP(i, H) REP(j, W)
		dp[i][j] = !in[i][j];
	FOR(i, 1, H) FOR(j, 1, W) {
		if(in[i][j])
			dp[i][j] = 0;
		else {
			dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
			width = max(width, dp[i][j]);
		}
	}
	return width * width;
}

int main() {
	int H, W;
	cin >> H >> W;
	REP(i, H) REP(j, W)
		cin >> in[i][j];

	cout << solve(H, W) << endl;
	return 0;
}
