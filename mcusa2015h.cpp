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
#include <bitset>
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
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
const int IINF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

bool b[250001];

int dfs(int start, int val, vector<pi> &v) {
	int cnt = 0;
	FOR(i, start, 18) {
		if(!(val >> i & 1)) {
			int val2 = val | (1 << i);
			if(val2 < 250001 && b[val2])
				cnt++;
			v.pb(mp(val2, i+1));
		}
	}
	return cnt;
}

int main() {
	int l;
	while(cin >> l) {
		if(l != -1) {
			b[l] = true;
			continue;
		}
		REP(i, 250001) {
			if(!b[i]) continue;

			int start = 0;
			REP(j, 18)
				if((i >> j) & 1) {
					start = j+1;
					break;
				}
			int cnt = 0;
			vector<pi> v;
			cnt += dfs(0, i, v);
			REP(j, v.size()) {
				vector<pi> v2;
				cnt += dfs(v[j].second, v[j].first, v2);
			}
			REP(j, 18) {
				if(i >> j & 1) {
					vector<pi> v2;
					cnt += dfs(j+1, i & ~(1 << j), v2);
				}
			}

			cout << i << ':' << cnt << endl;
		}
		memset(b, false, sizeof(b));
	}


	return 0;
}
