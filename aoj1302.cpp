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
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
const int IINF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

map<vs, int> m2;

int dfs(vs &v, int m, int mask) {
	if(v.size() < 2)
		return v.size()-1;
	if(m2.count(v))
		return m2[v];
	int ans = IINF;
	REP(i, m) {
		vs a, b;
		int mask2 = mask;
		if(!(mask2 >> i & 1)) {
			mask2 |= 1 << i;
			REP(j, v.size()) {
				if(v[j][v[j].size()-1-i] == '1')
					a.pb(v[j]);
				else
					b.pb(v[j]);
			}
			int res = max(dfs(b, m, mask2), dfs(a, m, mask2))+1;
			ans = min(ans, res);
		}
	}
	m2[v] = ans;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	while(cin >> m >> n, m|n) {
		m2.clear();
		vs v(n);
		REP(i, n)
			cin >> v[i];
		cout << dfs(v, m, 0) << endl;
	}
	return 0;
}
