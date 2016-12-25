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
#define FOR(i,a,b) for(int i = (a); i < (int)(b); i++)
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
const int IINF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

struct comp {
	bool operator()(const pi &a, const pi &b) {
		if(a.first == b.first)
			return a.second > b.second;
		return a.first < b.first;
	}
};

bool chk(int a, int n, bool b[]) {
	if(a < 1 || n < a || !b[a])
		return false;
	b[a] = false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k; cin >> k;
	while(k--)  {
		int n, s, m;
		cin >> n >> s >> m;

		bool b[500001] = {};
		fill(b+1, b+500001, true);
		b[s] = false;

		vi ans;

		priority_queue<pi, vector<pi>, comp> pq;
		pq.push(pi(0, s));

		while(!pq.empty()) {
			s = pq.top().second; pq.pop();
			int a[3] = {s/2, s*2, s*2+1};
			REP(i, 3)
				if(chk(a[i], n, b))
					pq.push(pi(abs(s - a[i]) % m, a[i]));
			ans.pb(s);
		}
		REP(i, ans.size()) {
			if(i) cout << ' ';
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}
