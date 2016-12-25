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

bool lsd(string &s1, string &s2, int d) {
	int dp[17][17];
	REP(i, s1.size()+1) dp[i][0] = i;
	REP(i, s2.size()+1) dp[0][i] = i;
	FOR(i, 1, s1.size()+1)
		FOR(j, 1, s2.size()+1) {
			dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]) + 1, dp[i-1][j-1] + (s1[i-1] == s2[j-1] ? 0 : 1));
			if(dp[i][j] > dp[i-1][j-1])

	REP(i, s1.size()+1) {
		REP(j, s2.size()+1)
			cout << dp[i][j];
		cout << endl;
	}


	if(dp[s1.size()][s2.size()] <= d)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s1 = "toshio", s2 = "yoshoi";
	cout << lsd(s1, s2, 2) << endl;

	int n, d;
	while(cin >> n >> d, n|d) {
		vector<string> vs(n);
		REP(i, n)
			cin >> vs[i];
		int cnt = 0;
		REP(i, n-1) FOR(j, i+1, n) {
			if(lsd(vs[i], vs[j], d)) {
				cout << vs[i] << ',' << vs[j] << endl;
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
