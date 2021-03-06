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
#include <complex>
using namespace std;
#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for(int i = a; i < (int)b; i++)
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> P;
typedef vector<P> G;

namespace std {
	bool operator < (const P& a, const P& b) {
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
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
#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]
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

	int N = 0;
	int a, b, c, d, e, f;
	while(cin >> a >> b >> c >> d >> e >> f, a|b|c|d|e|f) {
		G g;
		g.pb(P(0, 0));
		g.pb(P(10000, 0));
		g.pb(P(10000, 10000));
		g.pb(P(0, 10000));
		P c1((e+a)/2.0, (f+b)/2.0);
		P c2 = P(e-a, f-b) * P(0, 1) + c1;
		g = convex_cut(g, L(c1, c2));
		c1 = P((c+a)/2.0, (d+b)/2.0);
		c2 = P(c-a, d-b) * P(0, 1) + c1;
		g = convex_cut(g, L(c1, c2));
		cout << ++N << ' ' << area2(g) / 1e8 << endl;
	}
	return 0;
}
