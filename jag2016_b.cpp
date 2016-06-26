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
	int N, M, T;
	cin >> N >> M >> T;
	int ans = 0, pre;
	REP(i, N) {
		int in; cin >> in;
		if(!i)
			ans += in - M;
		else if(in - pre > M * 2)
			ans += in - pre - M * 2;
		if(i == N-1 && T - in > M)
			ans += T - in - M;
		pre = in;
	}
	cout << ans << endl;
	return 0;
}
