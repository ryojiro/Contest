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
	int n; cin >> n;
	bool b[100];
	memset(b, false, sizeof(b));
	int p; cin >> p;
	REP(i, p) {
		int in; cin >> in;
		b[in-1] = true;
	}
	int q; cin >> q;
	REP(i, q) {
		int in; cin >> in;
		b[in-1] = true;
	}
	bool flg = false;
	REP(i, n)
		if(!b[i]) flg = true;

	if(flg) cout << "Oh, my keyboard!" << endl;
	else cout << "I become the guy." << endl;
	return 0;
}
