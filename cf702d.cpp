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

int main() {
	int d, k, a, b, t;
	cin >> d >> k >> a >> b >> t;
	if(d <= k)
		cout << d * a << endl;
	else {
		int ans = 0;
		d -= k;
		ans += k * a;
		int cos = min(k * a + t, k * b);
		int times = d / k;
		d -= k * times;
		ans += cos * times;
		cos = min(d * a + t, d * b);
		ans += cos;
		cout << ans << endl;
	}
	return 0;
}
