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

bool chk(int i, int j, vector<string> &s) {
	if(i < 0 || j < 0 || s.size()-1 < i || s[i].size()-1 < j)
		return false;
	if(s[i][j] == '*') {
		s[i][j] = ' ';
		return true;
	}
	return false;
}

int dfs(int i, int j, vector<string> &s, int x, int y) {
	if(chk(i, j+1, s))
		return dfs(i, j+1, s, x+1, y);

	if(chk(i+1, j+1, s))
		return dfs(i+1, j+1, s, x, y+1);
	if(chk(i+1, j, s))
		return dfs(i+1, j, s, x, y+1);
	if(chk(i+1, j-1, s))
		return dfs(i+1, j-1, s, x, y+1);

	if(chk(i, j-1, s))
		return dfs(i, j-1, s, x+1, y);

	if(chk(i-1, j-1, s))
		return dfs(i-1, j-1, s, x, y);
	if(chk(i-1, j, s))
		return dfs(i-1, j, s, x, y);
	if(chk(i-1, j+1, s))
		return dfs(i-1, j+1, s, x, y);

	return x * y / 2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	bool flg = false;
	while(cin >> n, n) {
		if(flg)
			cout << "----------" << endl;
		flg = true;
		cin.ignore();
		vector<string> s(n);
		REP(i, n)
			getline(cin, s[i]);

		map<int, int> m;
		REP(i, n) {
			REP(j, s[i].size()) {
				if(s[i][j] == '*') {
					int res = dfs(i, j, s, 2, 1);
					m[res] = m[res] + 1;
				}
			}
		}

		for(auto i: m)
			cout << i.first << ' ' << i.second << endl;
	}
	return 0;
}
