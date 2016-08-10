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

void area(double bx, double by, double ux, double uy, bool b[201][201]) {
	FOR(i, bx, ux)
		FOR(j, by, uy)
			b[i][j] = true;
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, cnt = 1;
	while(cin >> n, n) {
		vector<double> x, y, bx, by, ux, uy;
		REP(i, n) {
			double x2, y2, r;
			cin >> x2 >> y2 >> r;
			x.pb(x2-r); x.pb(x2+r);
			y.pb(y2-r); y.pb(y2+r);
			bx.pb(x2-r); by.pb(y2-r);
			ux.pb(x2+r); uy.pb(y2+r);
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());

		x.erase(unique(x.begin(), x.end()), x.end());
		y.erase(unique(y.begin(), y.end()), y.end());

		REP(i, n) {
			bx[i] = find(x.begin(), x.end(), bx[i]) - x.begin();
			by[i] = find(y.begin(), y.end(), by[i]) - y.begin();
			ux[i] = find(x.begin(), x.end(), ux[i]) - x.begin();
			uy[i] = find(y.begin(), y.end(), uy[i]) - y.begin();
		}

		bool b[201][201] = {};
		REP(i, n)
			area(bx[i], by[i], ux[i], uy[i], b);

		double sum = 0;
		REP(i, x.size()) REP(j, y.size())
			if(b[i][j])
				sum += (x[i+1] - x[i]) * (y[j+1] - y[j]);

		cout << fixed << setprecision(2) << cnt << ' ' << sum << endl;

		cnt++;
	}
	return 0;
}
