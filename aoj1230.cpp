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
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int n, m[20], dp[20][1<<13 + 1];

int dfs(int idx, int rem){
	int &res = dp[idx][rem];
	if(res != -1) return res;
	if(rem == 1) return res = 0;
 
	FOR(i, 1, m[idx]+1) {
		if(rem - i < 1)
			break;
		if(!dfs((idx + 1) % n, rem - i))
			return res = 1;
	}
	return res = 0;
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> n, n) {
		n += n;
		int s; cin >> s;
		REP(i, n)
			cin >> m[i];
		memset(dp, -1, sizeof(dp));
		cout << dfs(0, s) << endl;
		/*
		REP(i, n*2) {
			REP(j, s)
				cout << dp[i][j] << ' ';
			cout << endl;
		}
		*/
	}
	return 0;
}
