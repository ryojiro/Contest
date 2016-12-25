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
const int IINF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void dfs(string &s, bool flg, int lmt, int pnt) {
	int n = s.size() - 1;
	if(lmt == 0) {
		if(flg) {
			if(s[n] == 9) {
				s[n] = '0';
				if(pnt == 0)
					s.insert(0, '1');
				else
					dfs(s, true, 0, pnt-1);
			}
			else
				s[n]++;
		}
		return;
	}
	if(s[n] + flg >= 5 + '0') {
		s.erase(n);
		dfs(s, true, --lmt);
	}
	else if(flg)
		s[n]++;
	return;
}

void check(string &s) {
	int cnt = 0;
	while(s[s.size()-1-cnt] == '0')
		cnt++;
	if(cnt) s.erase(s.size()-1-cnt);
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, t; cin >> n >> t;
	int pnt;
	string s; cin >> s;
	REP(i, s.size())
		if(s[i] == '.') {
			pnt = i;
			s.erase(pnt, 1);
		}
	dfs(s, false, t, n-1);
	check(s);
	if(s.size() > pnt)
		s.insert(s.begin()+pnt, '.');

	cout << s << endl;

	return 0;
}
