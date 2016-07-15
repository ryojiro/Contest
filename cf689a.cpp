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

bool chk(int i, int j) {
	if(0 <= i && i < 4 && 0 <= j && j < 3)
		return true;
	else
		return false;
}

int main() {
	int keys[4][3] = { {1,1,1},{1,1,1},{1,1,1},{0,1,0} };
	int n; cin >> n;
	string in; cin >> in;
	vector< vector<int> > in2;
	FOR(i, 1, n) {
		int in1, in11;
		if(in[i]  == '0') in1 = 11;
		else in1 = in[i] - '0';
		if(in[i-1]  == '0') in11 = 11;
		else in11 = in[i-1] - '0';
		vector<int> v;
		int y = (in1-1) / 3 - (in11-1) / 3;
		int x = in1 - y*3 - in11;
		v.push_back(y);
		v.push_back(x);
		in2.push_back(v);
	}
//	REP(i, in2.size())
//		cout << in2[i][0] << ' ' << in2[i][1] << endl;
//	cout << endl;
	bool flg = true;
	int cnt2 = 0;
	REP(i, 4) REP(j, 3) {
		if(i == 3 && (j == 0 || j == 2)) continue;
		int cnt = 0;
		int ni = i, nj = j;
		REP(k, in2.size()) {
			ni += in2[k][0]; nj += in2[k][1];
//			cout << "i " << i << " j " << j << ' ' << ni << ' ' << nj << ' ' << keys[ni][nj] << endl ;
			if(keys[ni][nj]  == 1 && chk(ni, nj))
				cnt++;
			if(cnt == in2.size()) {
				cnt2++;
				if(cnt2 > 1)
					flg = false;
			}
		}
//		cout << endl;
	}
	if(flg && n != 1) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
