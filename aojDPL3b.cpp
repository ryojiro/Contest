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
#include <stack>
#include <map>
#include <queue>
#include <complex>
using namespace std;
#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for(int i = a; i < (int)b; i++)
const int INF = 1<<28;
#define MAX 1401

int dp[MAX][MAX];

int solve(int H, int W) {
	REP(j,W) {
		int v = 1;
		REP(i, H) {
			if(!dp[i][j])
				v = 0;
			dp[i][j] = v++;
		}
	}

	REP(i, H+1) {
		REP(j, W+1)
			cout << dp[i][j] << ' ';
		cout << endl;
	}

	int ans = 0;
	REP(i, H) {
		pair<int, int> p, p2;
		stack< pair<int, int> > s;
		REP(j, W+1) {
			p = make_pair(dp[i][j], j);
			if(s.empty())
				s.push(p);
			else {
				if(s.top().first < p.first)
					s.push(p);
				else if(s.top().first > p.first) {
					int pnt = j;
					while(!s.empty() && s.top().first >= p.first) {
						p2 = s.top(); s.pop();
						ans = max(ans, p2.first * (j - p2.second));
						pnt = p2.second;
					}
					p.second = pnt;
					s.push(p);
				}
			}
		}
	}
	return ans;
}

int main() {
	int H, W; cin >> H >> W;
	REP(i, H) REP(j, W) {
		cin >> dp[i][j];
		dp[i][j] = !dp[i][j];
	}
	cout << solve(H, W) << endl;
	return 0;
}
