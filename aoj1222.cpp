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
const int INF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

double area(double a, double b, double c) {
	return sin((b-a)*2*M_PI)/2 + sin((c-b)*2*M_PI)/2 + sin((a-c)*2*M_PI)/2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	while(cin >> n >> m, n|m) {
		double dp[40][40][40] = {};
		double p[n];
		REP(i, n)
			cin >> p[i];
		REP(i, m-2) {
			REP(j, n-2) {
				FOR(k, j+2, n) {
					FOR(l, j+1, k) {
						if(i)
							dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][l] + area(p[j], p[l], p[k]));
						else
							dp[i][j][k] = max(dp[i][j][k], area(p[j], p[l], p[k]));
					}
				}
			}
		}
		double ans = -1;
		REP(i, n) REP(j, n)
			ans = max(ans, dp[m-3][i][j]);
		cout << fixed << setprecision(6) << ans << endl;
	}
	return 0;
}
