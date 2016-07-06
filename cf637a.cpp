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
	int m = 0, p = -1;
	cin >> n;
	int a[1000001] = {};
	REP(i, n) {
		int in; cin >> in;
		a[in]++;
		if(a[in] > m) {
			m = a[in];
			p = in;
		}
	}

	cout << p << endl;

		return 0;
}
