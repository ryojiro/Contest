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

int main() {
	int n, m; cin >> n >> m;
	vector<string> s(n);
	REP(i, n)
		cin >> s[i];
	bool flg = false, bad = false;
	int x = -1, y = -1;
	REP(i, n) {
		int cnt = 0;
		REP(j, m)
			if(s[i][j] == '*')
				cnt++;
		if(cnt > 1) {
			if(flg)
				bad = true;
			flg = true;
			x = i;
			REP(j, m)
				s[i][j] = '.';
		}
	}
	flg = false;
	REP(j, m) {
		int cnt = 0;
		REP(i, n)
			if(s[i][j] == '*')
				cnt++;
		if(cnt > 1) {
			if(flg)
				bad = true;
			flg = true;
			y = j;
			REP(i, n)
				s[i][j] = '.';
		}
	}
	flg = false;
	if(x == -1) {
		REP(i, n) {
			REP(j, m) {
				if(s[i][j] == '*') {
					x = i;
					s[i][j] = '.';
					flg = true;
					break;
				}
			}
			if(flg) break;
		}
	}
	flg = false;
	if(y == -1) {
		REP(i, n) {
			REP(j, m) {
				if(s[i][j] == '*') {
					y = j;
					s[i][j] = '.';
					flg = true;
					break;
				}
			}
			if(flg) break;
		}
	}
	if(x == -1) x = 0;
	if(y == -1) y = 0;
	/*
	REP(i, n) {
		REP(j, m) {
			cout << s[i][j];
		}
		cout << endl;
	}
*/
	REP(i, n)
		s[i][y] = '.';
	REP(i, m)
		s[x][i] = '.';
	REP(i, n) {
		REP(j, m) {
			if(s[i][j] == '*')
				bad = true;
			if(bad) break;
		}
		if(bad) break;
	}

	if(bad)
		cout << "NO" << endl;
	else
		cout << "YES" << endl << x + 1 << ' ' << y + 1 << endl;
	return 0;
}
