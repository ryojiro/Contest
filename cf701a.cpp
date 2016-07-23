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

int main() {
	int n; cin >> n;
	vi v(n), sum(n-1);
	REP(i, n)
		cin >> v[i];
	FOR(i, 1, n)
		sum.pb(v[0] + v[i]);
	vector<pi> vp;
	bool flg = false;
	set<int> s;
	REP(i, sum.size()) {
		vp.clear();
		s.clear();
		REP(j, v.size()) {
			REP(k, v.size()) {
				if(sum[i] == v[j] + v[k] && j != k) {
					if(!s.count(j) && !s.count(k)) {
						vp.pb(mp(j, k));
						s.insert(j);
						s.insert(k);
						if(vp.size() == n/2)
							flg = true;
						break;
					}
				}
				if(flg) break;
			}
			if(flg) break;
		}
		if(flg) break;
	}

	REP(i, vp.size())
		cout << vp[i].first+1 << ' ' << vp[i].second+1 << endl;
	return 0;
}
