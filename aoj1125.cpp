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
	int N;
	while(cin >> N, N) {
		int W, H;
		cin >> W >> H;

		bool map[100][100] = { false };
		REP(i, N) {
			int x, y;
			cin >> x >> y;
			map[y-1][x-1] = true;
		}

		int S, T;
		cin >> S >> T;
		int ans[100][100] = {};

		int cnt = 0;
		REP(i, H-T+1) {
			REP(j, W-S+1) {
				FOR(k, i, i+T) {
					FOR(l, j, j+S) {
						if(map[k][l]) ans[i][j]++;
					}
				}
				cnt = cnt > ans[i][j] ? cnt : ans[i][j];
			}
		}
//		REP(i, H) {
//			REP(j, W)
//				cout << ans[i][j] << ' ';
//			cout << endl;
//		}

		cout << cnt << endl;
	}
	return 0;
}
