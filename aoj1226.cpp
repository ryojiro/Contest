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
typedef unsigned long long ull;
const int IINF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

// Geometric Library
#include <complex>
#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]
typedef complex<double> P;
typedef vector<P> G;
const double EPS = 1e-8;
const double INF = 1e12;
namespace std {
	bool operator < (const P& a, const P& b) {
		//return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
		if(imag(a) < imag(b))
			return true;
		if(imag(a) == imag(b) && real(a) < real(b))
			return true;
		return false;
	}
}
double cross(const P& a, const P& b) { return imag(conj(a)*b); }
double dot(const P& a, const P& b) { return real(conj(a)*b); }
struct L : public vector<P> {
	L(const P &a, const P &b) {
		push_back(a); push_back(b);
	}
};
int ccw(P a, P b, P c) {
	b -= a; c -= a;
	if (cross(b, c) > 0) return +1; // counter clockwise
	if (cross(b, c) < 0) return -1; // clockwise
	if (dot(b, c) < 0) return +2; // c--a--b on line
	if (norm(b) < norm(c)) return -2; // a--b--c on line
	return 0;
}
P crosspoint(const L &l, const L &m) {
	double A = cross(l[1] - l[0], m[1] - m[0]);
	double B = cross(l[1] - l[0], l[1] - m[0]);
	if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
	return m[0] + B / A * (m[1] - m[0]);
}
G convex_cut(const G& g, const L& l) {
	G Q;
	for (int i = 0; i < g.size(); ++i) {
		P A = curr(g, i), B = next(g, i);
		if (ccw(l[0], l[1], A) != -1) Q.push_back(A);
		if (ccw(l[0], l[1], A)*ccw(l[0], l[1], B) < 0)
		Q.push_back(crosspoint(L(A, B), l));
	}
	return Q;
}
double area2(const G& g) {
	double A = 0;
	for (int i = 0; i < g.size(); ++i) 
		A += cross(curr(g, i), next(g, i));
	return A / 2.0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int n;
	while(cin >> n, n) {
		vector<G> v(n+2);
		REP(i, 4) {
			REP(j, n) {
				double in; cin >> in;
				if(i == 0)
					v[0].pb(P(0, in));
				else if(i == 1)
					v[n+1].pb(P(1, in));
				else if(i == 2)
					v[j+1].pb(P(in, 0));
				else if(i == 3)
					v[j+1].pb(P(in, 1));
			}
		}
		REP(i, n)
			REP(j, n)
				v[i+1].pb(crosspoint(L(v[i+1][0], v[i+1][1]), L(v[0][j], v[n+1][j])));
		v[0].pb(P(0, 0)); v[0].pb(P(0, 1));
		v[n+1].pb(P(1, 0)); v[n+1].pb(P(1, 1));
		REP(i, n+2)
			sort(v[i].begin(), v[i].end());
		double ans = 0;
		REP(i, n+1) {
			REP(j, n+1) {
				G g;
				g.pb(v[i][j]);
				g.pb(v[i+1][j]);
				g.pb(v[i+1][j+1]);
				g.pb(v[i][j+1]);
				ans = max(ans, area2(g));
			}
		}
		cout << ans << endl;
	}
	return 0;
}
