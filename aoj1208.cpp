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

int n, p, s1, s2, l1, l2;
void sternBrocot(int p, int n, int pl, int ql, int pr, int qr) {
	int pm = pl + pr, qm = ql + qr;
	if(pm > n || qm > n)
		return;
	if(pm * pm  > p * qm * qm) {
		l1 = pm; l2 = qm;
		sternBrocot(p, n, pl, ql, pm, qm);
	}
	else {
		s1 = pm; s2 = qm;
		sternBrocot(p, n, pm, qm, pr, qr);
	}
}
int main() {
	while(cin >> p >> n, p|n) {
		sternBrocot(p, n, 0, 1, 1, 0);
		cout << l1 << '/' << l2 << ' ' << s1 << '/' << s2 << endl;
	}
	return 0;
}
