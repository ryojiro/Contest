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
	int bill;
	const int cur[4] = {10, 50, 100, 500};
	bool first = false;
	while(cin >> bill, bill) {
		if(first) cout << endl;
		int sum = 0, in[4];
		REP(i, 4) {
			cin >> in[i];
			sum += cur[i] * in[i];
		}
		sum -= bill;
		for(int i=3; i>=0; i--) {
			while(sum >= cur[i]) {
				sum -= cur[i];
				in[i]--;
			}
		}

		REP(i, 4) if(in[i] > 0) cout << cur[i] << ' ' << in[i] << endl;
		first = true;
	}
	return 0;
}

//copied
