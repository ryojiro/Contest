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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int dp[501] = {};
	int n, m; cin >> n >> m;
	REP(i, n) {
		int v, t; cin >> v >> t;
		for(int j = 500; j >= t; j--)
			dp[j] = max(dp[j], dp[j-t] + v);
	}
	cout << dp[m] << endl;
	return 0;
}
