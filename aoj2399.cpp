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
	int n;
	while(cin >> n, n) {
		vector< vector<int> > f;
		REP(i, n) {
			int m; cin >> m;
			vector<int> hoge;
			REP(j, m) {
				int in; cin >> in;
				hoge.push_back(in);
			}
			sort(hoge.begin(), hoge.end());
			f.push_back(hoge);
		}
		int k; cin >> k;
		int cnt, ans = 0;
		vector<int> l;
		REP(i, k) {
			int in; cin >> in;
			l.push_back(in);
		}
//		sort(l.begin(), l.end());

//		REP(i, n) REP(j, f[i].size()) cout << i << ' ' << j << ' ' << f[i][j] << endl;
		REP(i, f.size()) {
			cnt = 0;
			REP(j, f[i].size()) {
				if(f[i][j] == l[cnt])
					cnt++; 
				if(cnt == k) {
					if(!ans) ans = i+1;
					else ans = -1;
					break;
				}
			}
		}
		if(ans == 0) ans = -1;
		cout << ans << endl;
	}
	return 0;
}
