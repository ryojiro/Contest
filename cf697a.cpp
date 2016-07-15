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
	int t, s, x;
	cin >> t >> s >> x;
	bool flg = false;
	int t2 = t+1;
	while(t <= x) {
		if(t == x || t+1 == x)
			if(t2 != x)
				flg = true;
		t += s;
	}
	if(flg)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
