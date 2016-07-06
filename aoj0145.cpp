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

int ans = INF;
int dp[101][101] = {};

void filldp(vector< pair<int, int> > &v) {
	FOR(i, 1, v.size())
		for(int j=0; j < v.size() - i; j++)
			dp[i][j] = v[i].first * v[i].second * v[j].first * v[j].second;
	REP(i, v.size()) {
		REP(j,v.size())
			cout << dp[i][j] << ' ';
		cout << endl;
	}

	return;
}

int main() {
	int n; cin >> n;
	vector< pair<int, int> > cards(n);
	REP(i, n)
		cin >> cards[i].first >> cards[i].second;
	filldp(cards);
	return 0;
}
