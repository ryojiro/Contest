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

int W, H, ppl;
char m[30][30];
string d = "WSEN";
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

bool canMove(int h, int w) {
	if(0 <= h && 0 <= w && h < H && w < W)
		if(m[h][w] == '.' || m[h][w] == 'X')
			return true;
	return false;
}

char decideDirection(int h, int w, char d2) {
	REP(i, 4) {
		int nd = (d.find(d2) + 3 + i) % 4;
		int nh = h + dy[nd], nw = w + dx[nd];
		if(canMove(nh, nw)) return d[nd];
	}
	return d2;
}

int main() {
	while(cin >> W >> H, W|H) {
		ppl = 0;
		REP(i, H) REP(j, W) {
			cin >> m[i][j];
			if(d.find(m[i][j]) != string::npos)
				ppl++;
		}

		int cnt = 0;
		while(ppl) {
			REP(i, H) REP(j, W) {
				if(d.find(m[i][j]) != string::npos) {
					m[i][j] = decideDirection(i, j ,m[i][j]);
				}
			}

			bool chk[30][30];
			memset(chk, true, sizeof(chk));
			REP(i, 4) REP(j, H) REP(k, W) {
				if(m[j][k] == d[i] && chk[j][k]) {
					int nh = j + dy[i], nw = k + dx[i];
					if(m[nh][nw] == '.' && chk[nh][nw]) {
						swap(m[j][k], m[nh][nw]);
						chk[nh][nw] = false;
					}
					else if(m[nh][nw] == 'X' && chk[nh][nw]) {
						m[j][k] = '.';
						chk[nh][nw] = false;
						ppl--;
					}
					chk[j][k] = false;
				}
			}
			cnt++;
			if(cnt > 180) break;

			//debug
//			REP(i, H) {
//				REP(j, W)
//					cout << m[i][j];
//				cout << endl;
//			}
		}
		if(cnt > 180) cout << "NA" << endl;
		else cout << cnt << endl;
	}
	return 0;
}
