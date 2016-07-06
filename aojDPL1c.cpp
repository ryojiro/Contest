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

int main() {
	int N, W; cin >> N >> W;
	vector< pair<int, int> > vii(N);
	REP(i, N)
		cin >> vii[i].second >> vii[i].first;

	int dp[10001] = {};
	FOR(i, 1, W+1) {
		REP(j, N) {
			if(i >= vii[j].first)
				dp[i] = max(dp[i], dp[i - vii[j].first] + vii[j].second);
			else
				dp[i] = max(dp[i], dp[i-1]);
		}
	}
//	REP(i, W+1) cout << dp[i] << ' ';
	cout << dp[W] << endl;
	return 0;
}
