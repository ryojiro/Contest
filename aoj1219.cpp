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
const int INF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

struct guard {
	vector<bool> cycle;
	int cnt;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int g, d;
	while(cin >> g >> d, g|d) {
		vector<guard> v(g);
		REP(i, g) {
			int in, in2 = 1;
			while(cin >> in, in) {
				REP(j, in)
					v[i].cycle.pb(in2);
				in2 = (in2 + 1) % 2;
			}
		}

		queue<int> q;
		set<int> s;
		REP(i, d) {
			REP(j, g) {
				if(v[j].cycle[v[j].cnt % v[j].cycle.size()])
					v[j].cnt++;
				else {
					if(!s.count(j)) {
						q.push(j);
						s.insert(j);
					}
				}
			}
			if(q.size()) {
				int top = q.front();
				v[top].cnt++;
				if(v[top].cycle[v[top].cnt % v[top].cycle.size()]) {
					q.pop(); s.erase(top);
				}
			}
		}
		int ans = 0;
		REP(i, g)
			ans += d - v[i].cnt;
		cout << ans << endl;
	}
	return 0;
}
