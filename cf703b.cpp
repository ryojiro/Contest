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
	int n, k; cin >> n >> k;
	ll sum = 0LL, ans = 0LL;
	int c[100001];
	FOR(i, 1, n+1) {
		cin >> c[i];
		sum += c[i];
	}
	bool id[100001] = {};
	REP(i, k) {
		int in; cin >> in;
		id[in] = true;
		sum -= c[in];
		ans += c[in] * sum;
	}
	FOR(i, 1, n+1) {
		if(i != n && !id[i] && !id[i+1])
			ans += c[i] * c[i+1];
		if(i == n && !id[i] && !id[1])
				ans += c[i] * c[1];
	}
	cout << ans << endl;
	return 0;
}
