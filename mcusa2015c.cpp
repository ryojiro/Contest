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


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n) {
		bool table[10][128] = {};
		REP(i, n) {
			string in; cin >> in;
			REP(j, in.size())
				table[i][in[j]] = true;
		}
		int dp[10][10] = {};

		int ans = IINF;
		vi seq;
		REP(i, n) seq.pb(i);
		do {
			int cnt = 0;
			FOR(i, 1, n) {
				if(dp[seq[i-1]][seq[i]])
					cnt += dp[seq[i-1]][seq[i]];
				else {
					int cnt2 = 0;
					FOR(j, 'A', 'Z'+1)
						if(table[seq[i-1]][j] && table[seq[i]][j])
							cnt2++;
					dp[seq[i-1]][seq[i]] = cnt2;
					dp[seq[i]][seq[i-1]] = cnt2;
					cnt += cnt2;
				}
				}
			ans = min(ans, cnt);
		} while(next_permutation(seq.begin(), seq.end()));

		cout << ans << endl;
	}
	return 0;
}
