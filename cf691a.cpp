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
	int cnt =  0;
	REP(i, n) {
		int in; cin >> in;
		if(in == 0)
			cnt++;
	}
	if(n == 1) {
		if(cnt == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	else if(cnt == 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
