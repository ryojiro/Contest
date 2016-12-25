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
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<pi> vp(n);
	pi sum = pi(0,0);
	REP(i, n) {
		cin >> vp[i].first >> vp[i].second;
		sum.first += vp[i].first;
		sum.second += vp[i].second;
	}
	int now = abs(sum.first - sum.second);
	pi now2 = pi(now, -1);
	REP(i, n) {
		pi tmp = pi(sum.first - vp[i].first + vp[i].second, sum.second - vp[i].second + vp[i].first);
		if(now2.first < abs(tmp.first - tmp.second)) {
			now2.first = abs(tmp.first - tmp.second);
			now2.second = i;
		}
	}
	if(now2.second == -1)
		cout << 0 << endl;
	else
		cout << now2.second + 1 << endl;


	return 0;
}
