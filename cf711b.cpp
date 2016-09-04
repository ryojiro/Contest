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

	int n; cin >> n;
	ll a[501][501] = {}, w[501] = {}, h[501] = {};
	pi p;
	REP(i, n) REP(j, n) {
		cin >> a[i][j];
		if(a[i][j] == 0)
			p = pi(i, j);
		w[i] += a[i][j];
		h[j] += a[i][j];
	}
	bool flg = false;
	ll b = 0;
	REP(i, n) {
		if(i == p.first || i == p.second)
			continue;
		if(w[i] != h[i])
			flg = true;
		else
			b = w[i];
	}
	a[p.first][p.second] = b - w[p.first];
	w[p.first] += a[p.first][p.second];
	h[p.second] += a[p.first][p.second];

	ll r = 0, l = 0;
	REP(i, n) {
		r += a[i][i];
		l += a[i][n-i-1];
	}
	REP(i, n)
		if(w[i] != h[i])
			flg = true;
	if(r != b || l != b)
		flg = true;

	if(flg)
		cout << -1 << endl;
	else {
		if(n == 1)
			cout << 1 << endl;
		else if(a[p.first][p.second] < 1)
			cout << -1 << endl;
		else
			cout << a[p.first][p.second] << endl;
	}
	return 0;
}
