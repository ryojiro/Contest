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

int main() {
	int n, m, a;
	while(cin >> n >> m >> a, n|m|a) {
		vector<pair<int, pair<int, int> > > ppi;
		REP(i, m) {
			int in[3];
			REP(j, 3) cin >> in[j];
			ppi.push_back(make_pair(in[0], make_pair(in[1], in[2])));
			sort(ppi.begin(), ppi.end());
			reverse(ppi.begin(), ppi.end());
		}
		int ans = a;
		int now = INF;
		REP(i, ppi.size()) {
			if(ppi[i].first == now) continue;
			if(ppi[i].second.first == ans) {
				ans = ppi[i].second.second;
				now = ppi[i].first;
			}
			else if(ppi[i].second.second == ans) {
				ans = ppi[i].second.first;
				now = ppi[i].first;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
