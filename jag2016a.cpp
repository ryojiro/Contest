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
	int N; cin >> N;
	int a = 0, un = 0;
	bool flg = true;
	REP(i, N) {
		string in; cin >> in;
		if(in == "A")
			a++;
		else if(in == "Un") {
			un++;
			if(a < un)
				flg = false;
		}
	}
	if(flg && a == un)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
