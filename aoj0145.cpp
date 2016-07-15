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
#define MAX 100
const int INF = 1<<28;

int main() {
	int n, dp[100][100] = {}, c[100][2];
	cin >> n;
	REP(i,n)
		cin >> c[i][0] >> c[i][1];
	REP(i, 100) REP(j, 100) {
		if(i == j) continue;
		dp[i][j] = INF;
	}
	FOR(i, 1, n)
		REP(j, n-i)
			FOR(k, j, j+i) {
				dp[j][j+i] = min(dp[j][j+i], dp[j][k] + dp[k+1][j+i] + c[j][0] * c[k][1] * c[k+1][0] * c[j+i][1]);
				cout << "i " << i << " j " << j << " k " << k << ' ' << dp[j][j+i] << endl;
			}
	REP(i, 10) {
		REP(j, 10) {
			if(dp[i][j] == INF)
				cout << "INF ";
			else
				cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	cout << dp[0][n-1] << endl;
	return 0;
}
