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
#include <queue>
#include <complex>
using namespace std;
#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for(int i = a; i < (int)b; i++)
const int INF = 1<<28;

const int MAXN=16;
int n;
int d[MAXN][MAXN];
int dp[1<<MAXN][MAXN];

int rec(int S, int v) {
	if(dp[S][v] >= 0)
		return dp[S][v];
	if(S == (1<<n)-1 && v==0)
		return dp[S][v] = 0;
	int tmp=INF;
	REP(u,n)
		if(!(S>>u & 1))
			tmp = min(tmp, rec(S | 1<<u, u) + d[v][u]);
	return dp[S][v] = tmp;
}
string debug(int i) {
	if(i == INF)
		return "INF";
	else
		return to_string(i);
}
int main() {
	int m; cin >> n >> m;
	REP(i,n) REP(j,n)
		d[i][j] = d[j][i] = INF;
	REP(i,m) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = d[b][a] = c;
	}
	fill((int *)dp, (int *)(dp + (1<<MAXN)), -1);
	int ans = rec(0,0);
	cout << (ans==INF? -1:ans) << endl;
/*
	REP(i, 16) {
		REP(j, 16)
			cout << debug(d[i][j]) << ' ';
		cout << endl;
	}
	REP(i, 1<<16) {
		REP(j, 16)
			cout << debug(dp[i][j]) << ' ';
		cout << endl;
	}
*/
	return 0;
}
