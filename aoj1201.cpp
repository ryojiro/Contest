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

int cnt;
string s[2][10];
bool same[10];

bool chk(string &a, string &b, int &pnt) {
	REP(i, 5) {
		if(a[i*5 + pnt - 5] == b[i])
			return false;
	}
	return true;
}

void dfs(int pnt, string done, bool b[2][10]) {
	if(pnt == 10) {
		cnt++;
		return;
	}
	if(pnt < 5) {
		REP(i, 2) REP(j, 10) {
			if(!b[i][j]) {
				b[0][j] = true;
				b[1][j] = true;
				dfs(pnt+1, done + s[i][j], b);
				b[0][j] = false;
				if(!same[j]) b[1][j] = false;
			}
		}
	}
	else {
		REP(i, 2) REP(j, 10) {
			if(!b[i][j] && chk(done, s[i][j], pnt)) {
				b[0][j] = true;
				b[1][j] = true;
				dfs(pnt+1, done + s[i][j], b);
				b[0][j] = false;
				if(!same[j]) b[1][j] = false;
			}
		}
	}
	return;
}

int main() {
	string in;
	while(cin >> in, in != "END") {
		bool b[2][10] = {};
		REP(i, 10) {
			if(i)
				cin >> in;
			s[0][i] = in;
			reverse(in.begin(), in.end());
			s[1][i] = in;
			same[i] = s[0][i] == s[1][i] ? true:false;
		}
		cnt = 0;
		dfs(0, "", b);
		cout << cnt / 8 << endl;
	}
	return 0;
}
