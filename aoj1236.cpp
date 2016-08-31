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
	while(n--) {
		vi a, c, d;
		vector<vi> v(100);
		int in;
		while(cin >> in, in)
			a.pb(in);
		int cur = 0, top = 1;
		c.pb(0); d.pb(a[0]);
		FOR(i, 1, a.size()) {
			if(a[i] > 0) {
				c.pb(c[cur]+1); d.pb(a[i]);
				v[top].pb(cur); v[cur].pb(top);
				d[top]--; d[cur]--;
				cur = top++;
			}
			else {
				int to;
				for(int j = cur; j >= 0; j--) {
					if(c[j] - c[cur] == a[i] && d[j] > 0) {
						to = j;
						break;
					}
				}
				v[to].pb(cur); v[cur].pb(to);
				d[to]--; d[cur]--;
				if(i == a.size()-1)
					break;
			}
			while(!d[cur]) cur--;
		}
		REP(i, top) {
			cout << i+1;
			sort(v[i].begin(), v[i].end());
			REP(j, v[i].size())
				cout << ' ' << v[i][j]+1;
			cout << endl;
		}
	}
	return 0;
}
