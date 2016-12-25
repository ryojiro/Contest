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
const int INF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main() {
	int m, c, n;
	while(cin >> m >> c >> n, m|c|n) {
		vector<vi> d(m), ppl(n);
		int cnt = 0;
		REP(i, n) {
			int k; cin >> k;
			ppl[i].resize(k);
			REP(j, k)
				cin >> ppl[i][j];
		}

		int lmt = 0;
		for(int loop=0;; loop = (loop+1)%n) {
			if(!ppl[loop].size()) {
				if(lmt++ > n) break;
				continue;
			}
			lmt = 0;
			int book = *ppl[loop].begin();
			ppl[loop].erase(ppl[loop].begin());

			//take a book
			bool flg = false;
			REP(i, m) {
				REP(j, d[i].size()) {
					if(d[i][j] == book) {
						d[i].erase(d[i].begin() + j);
						cnt += i+1;
						flg = true;
						break;
					}
				}
				if(flg) break;
			}
			if(!flg) cnt += m+1;

			//return a book
			flg = false;
			bool flg2 = false;
			int put = m;
			REP(i, m) {
				if(d[i].size() < c) {
					d[i].pb(book);
					flg = true;
					cnt += i+1;
					put = i;
					if(!i) flg2 = true;
					break;
				}
			}
			if(flg2) continue;
			if(!flg) cnt += m+1;


			//set
			int get = *d[0].begin();
			d[0].erase(d[0].begin());
			cnt += 1;

			flg = false;
			FOR(i, 1, m) {
				if(d[i].size() < c) {
					flg = true;
					cnt += i+1;
					d[i].pb(get);
					break;
				}
			}
			if(!flg) cnt += m+1;

			d[put].erase(d[put].end()-1);
			d[0].pb(book);
			cnt += put + 2;

		}
		cout << cnt << endl;
	}
	return 0;
}
