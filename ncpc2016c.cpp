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

pi change(string s) {
	pi p;
	if(s[0] == 'T') p.first = 10;
	else if(s[0] == 'J') p.first = 11;
	else if(s[0] == 'Q') p.first = 12;
	else if(s[0] == 'K') p.first = 13;
	else if(s[0] == 'A') p.first = 1;
	else p.first = s[0] - '0';

	if(s[1] == 's') p.second = 1;
	else if(s[1] == 'h') p.second = 2;
	else if(s[1] == 'd') p.second = 3;
	else if(s[1] == 'c') p.second = 4;

	return p;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<pi> card;
	REP(i, n) {
		string in; cin >> in;
		card.pb(change(in));
	}

	int v[] = {1,2,3,4};
	vector< map<pi, int> > options;
	do {
		REP(i, 4) REP(j, 1<<4) {
			map<pi, int> m;
			int pri = 0;
			REP(k, 4) {
				FOR(l, 1, 14) {
					if(j >> k & 1)
						m[pi(l, v[k])] = pri++;
					else
						m[pi(14 - l, v[k])] = pri++;
				}
			}
			options.pb(m);
		}
	} while(next_permutation(v, v+4));

	int ans = INF;
	REP(i, options.size()) {
		vi list;
		int cnt = 0;
		REP(j, n)
			list.pb(options[i][card[j]]);
		FOR(j, 1, n) {
			bool flg = false;
			int k = j;
			while(k > 0 && list[k-1] > list[k]) {
				flg = true;
				swap(list[k-1], list[k]);
				k--;
			}
			cnt += flg;
			if(ans < cnt) break;
		}
		ans = min(ans, cnt);
	}
	cout << ans << endl;

	return 0;
}
