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
	int n, k;
	cin >> n >> k;
	int a[1000000] = {};
	bool flg = false;
	REP(i, n) {
		int in; cin >> in;
		a[7 % in]++;
		if(a[7 % in] > 1) flg = true;
	}
	if(flg) cout << "No" << endl;
	else cout << "Yes" << endl;

	return 0;
}
