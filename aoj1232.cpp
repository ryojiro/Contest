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
#include <complex>
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

vi v;
void sieve() {
	bool prime[50000];
	fill(prime, prime+50000, true);
	prime[0] = prime[1] = false;
	REP(i, 50000)
		if(prime[i])
			for(int j = i*2; j < 50000; j += i)
				prime[j] = false;
	REP(i, 50000)
		if(prime[i])
			v.pb(i);
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	sieve();
	int m, a, b;
	while(cin >> m >> a >> b, m|a|b) {
		ll max = 0;
		int p, q;
		REP(i, v.size()) {
			REP(j, v.size()) {
				if(v[i] * v[j] > m)
					break;
				if(v[i] * v[j] <= m && (double)a/b <= (double)v[i]/v[j]
						&& (double)v[i]/v[j] <= 1 && v[i] * v[j] > max) {
					max = v[i] * v[j];
					p = v[i]; q = v[j];
				}
			}
		}
		cout << p << ' ' << q << endl;
	}
	return 0;
}
