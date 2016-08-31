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

struct point {
	double x, y, z;
};

double dis(point p1 , point p2) {
	double x = (p1.x - p2.x) * (p1.x - p2.x);
	double y = (p1.y - p2.y) * (p1.y - p2.y);
	double z = (p1.z - p2.z) * (p1.z - p2.z);
	return sqrt(x + y + z);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	REP(_, n) {
		double qr, rp, pq;
		cin >> qr >> rp >> pq;
		int m; cin >> m;
		vector<point> v(m);
		REP(i, m)
			cin >> v[i].x >> v[i].y >> v[i].z;
		REP(i, m) {
			REP(j, m) {
				if(i == j)
					continue;
				double a = dis(v[i], v[j]);
				double rate = a / pq;
				REP(k, m) {
					if(i == k || j == k)
						continue;
					double b = dis(v[j], v[k]);
					double c = dis(v[k], v[i]);
					if(abs(rate - b / qr) < 1e-3 && abs(rate - c / rp) < 1e-3) {
						cout << i+1 << ' ' << j+1 << ' ' << k+1 << endl;
					}
				}
			}
		}
	}
	return 0;
}
