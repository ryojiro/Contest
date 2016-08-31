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
const int INF = 1<<28;
const ll MOD = 1000000007;

int n;
bool flg;
vi a;
set<ull> s;
int d[9][9] = {
	{0, 1, 2, 3, 6, INF},
	{-1, 0, 1, 3, 6, INF},
	{-2, -1, 0, 3, 6, INF},
	{-3, 0, 1, 2, 3, INF},
	{-3, -1, 0, 1, 3, INF},
	{-3, -2, -1, 0, 3, INF},
	{-6, -3, 0, 1, 2, INF},
	{-6, -3, -1, 0, 1, INF},
	{-6, -3, -2, -1, 0, INF}
};

bool chk(int cnt, int cl, string &now) {
	if(cl == 0 && (0b1100110000000000 & a[cnt]) == 0) {
		now[0] = now[1] = now[4] = now[5] = '7';
		return true;
	}
	if(cl == 1 && (0b0110011000000000 & a[cnt]) == 0) {
		now[1] = now[2] = now[5] = now[6] = '7';
		return true;
	}
	if(cl == 2 && (0b0011001100000000 & a[cnt]) == 0) {
		now[2] = now[3] = now[6] = now[7] = '7';
		return true;
	}
	if(cl == 3 && (0b0000110011000000 & a[cnt]) == 0) {
		now[4] = now[5] = now[8] = now[9] = '7';
		return true;
	}
	if(cl == 4 && (0b0000011001100000 & a[cnt]) == 0) {
		now[5] = now[6] = now[9] = now[10] = '7';
		return true;
	}
	if(cl == 5 && (0b0000001100110000 & a[cnt]) == 0) {
		now[6] = now[7] = now[10] = now[11] = '7';
		return true;
	}
	if(cl == 6 && (0b0000000011001100 & a[cnt]) == 0) {
		now[8] = now[9] = now[12] = now[13] = '7';
		return true;
	}
	if(cl == 7 && (0b0000000001100110 & a[cnt]) == 0) {
		now[9] = now[10] = now[13] = now[14] = '7';
		return true;
	}
	if(cl == 8 && (0b0000000000110011 & a[cnt]) == 0) {
		now[10] = now[11] = now[14] = now[15] = '7';
		return true;
	}
	return false;
}

void dfs(int cnt, int cl, string now) {
	if(flg) return;
	REP(i, 16) {
		if(now[i] == '0') return;
		now[i]--;
	}
	if(cnt == n) flg = true;
	REP(i, 9) {
		if(d[cl][i] == INF) break;
		string now2 = now;
		if(chk(cnt, cl + d[cl][i], now2)) {
			ull u = stoull(now2) * 10000 + cnt + 10 + cl+d[cl][i];
			if(!s.count(u)) {
				s.insert(u);
				dfs(cnt+1, cl + d[cl][i], now2);
			}
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> n, n) {
		flg = false;
		a.clear();
		s.clear();
		REP(i, n) {
			a.pb(0);
			REP(j, 16) {
				int in; cin >> in;
				if(j)
					a[i] <<= 1;
				a[i] |= in;
			}
		}
		if((a[0] & 0b0000011001100000)) {
			cout << 0 << endl;
			continue;
		}
		dfs(1, 4, "6666677667766666");
		cout << flg << endl;
	}
	return 0;
}
