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
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main() {
	int n, t;
	while(cin >> n, n) {
		cin >> t;
		vi v(n);
		bool b[100] = {};
		int pnt = 0;
		int ans, cnt;
		for(int i=0;; i++) {
			if(b[i%n]) continue;
			v[i%n]++;
			if(pnt%t == t-1) {
				b[i%n] = true;
				v[i%n] = -1;
				int mn = INF, mx = -1;
				cnt = 0;
				REP(j, n) {
					if(b[j]) continue;
					mn = min(mn, v[j]);
					mx = max(mx, v[j]);
					cnt++;
				}
				ans = mn;
				if(mn == mx) break;
			}
			pnt++;
		}
		cout << cnt << ' ' << ans << endl;
	}

	return 0;
}
