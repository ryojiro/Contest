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
const int INF = 1<<30;

int main() {
	int n; cin >> n;
	string s; cin >> s;
	vi r, l;
	REP(i, n) {
		int in; cin >> in;
		if(s[i] == 'R')
			r.pb(in);
		else
			l.pb(in);
	}
	int ans = INF;
	int i = 0, j = 0;
	while(r.size() && l.size()) {
		if(r[i] > l[j])
			j++;
		else {
			ans = min(ans, (l[j] - r[i]) / 2);
			i++;
		}
		if(i == r.size() || j == l.size())
			break;
	}
	if(ans == INF)
		cout << -1 << endl;
	else
		cout << ans << endl;

	return 0;
}
