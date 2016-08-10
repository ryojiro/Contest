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
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vi v1, v2;
	for(int i=0; i*i*i <= 151200; i++)
		v1.pb(i*i*i);
	for(int i=0; i*(i+1)*(i+2)/6 <= 151200; i++)
		v2.pb(i*(i+1)*(i+2)/6);

	int n;
	while(cin >> n, n) {
		int ans = 0;
		REP(i, v1.size())
			REP(j, v2.size())
				if(v1[i] + v2[j] <= n && v1[i] + v2[j] > ans) {
					ans = v1[i] + v2[j];
				}
		cout << ans << endl;
	}
	return 0;
}
