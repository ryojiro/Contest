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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b; cin >> a >> b;
	int n; cin >> n;
	double ans = INF;
	REP(i, n) {
		int x, y, v;
		cin >> x >> y >> v;
		double dis;
		dis = sqrt((double)(x-a)*(x-a) + (double)(y-b)*(y-b));
		ans = min(ans, dis/v);
	}
	cout << fixed << setprecision(6) << ans << endl;
	return 0;
}
