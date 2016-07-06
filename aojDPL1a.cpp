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
	int n, m; cin >> n >> m;
	vector<int> c, rslt;
	REP(i, m) {
		int in; cin >> in;
		c.push_back(in);
	}
	REP(i, n+1)
		rslt.push_back(n+1);
	rslt[0] = 0;
	FOR(i, 1, n+1) {
		REP(j, m) {
			if(i >= c[j]) {
				int tmp = rslt[i - c[j]] + 1;
				if(tmp < rslt[i])
					rslt[i] = tmp;
			}
		}
	}
//	REP(i, rslt.size()) cout << rslt[i] << endl;
	cout << rslt[n] << endl;
	return 0;
}



/*
int main() {
	int n, m; cin >> n >> m;
	vector<int> c(m), results(n+1);
	for(int i = 0; i < m; ++i)
		cin >> c[i];
	results[0] = 0;

	for(int i = 1; i <= n; ++i) {
		results[i] = n + 1; //最大値入力

		for(int j = 0; j < m; ++j) {
			if(i >= c[j]) { //1番からみていった値がお金よりも大きかった場合
				int tmpCoins = results[i - c[j]] + 1; //それよりもお金分前のところの数字から一つ足す
				cout << tmpCoins << " tmp " << i << " i " << c[j] <<  endl; 
				if(tmpCoins < results[i]) //もし、その結果が現在地よりも小さかったら
					results[i] = tmpCoins; //更新
			}
		}
	}
	cout << results[n] << endl;
}
*/
