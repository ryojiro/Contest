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
	vector<int> a;
	REP(i, n) {
		int in; cin >> in;
		a.push_back(in);
	}
	int same = 0;
	REP(i, a.size()) {
		for(int j=i+1; j< a.size(); j++) {
			int c1 = a[i], c2 = a[j];
			int cnt = 0;
			REP(j, 6) {
				if(c1 % 10 == c2 % 10)
					cnt++;
				c1 /= 10; c2 /= 10;
				if(!c1 || !c2) break;
			}
			same = cnt > same ? cnt : same;
		}
	}

	if(same > 3) cout << '0' << endl;
	else if(same > 1) cout << '1' << endl;
	else cout << '2' << endl;

	return 0;
}
