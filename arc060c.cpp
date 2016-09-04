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
const int INF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a; cin >> n >> a;
	int dp[51][2501] = {};
	int in[n];
	REP(i, n) {
		cin >> in[i];
		dp[0][in[i]]++;
	}
	FOR(k, 1, n)
		REP(j, 2501)
			if(dp[k-1][j])
				dp[k][j+in[k]] = dp[k-1][j] + dp[k-1][j+in[k]];

	int cnt = 0;
	REP(i, n)
			cnt += dp[i][a * (i+1)];

	cout << cnt << endl;

	REP(i, n) {
		REP(j, 100)
			cout << dp[i][j];
		cout << endl;
	}
	return 0;
}
