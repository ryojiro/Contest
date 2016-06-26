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
	int e;
	while(cin >> e, e) {
		bool flg = false;
		int rslt = 1;
		FOR(i, 0, e) {
			int ans = pow(i, 1.0 / 3.0);
			cout << ans << " ans" << endl;
			FOR(j, 0, i) {
				int s = ans;
				s += pow(j, 1.0 / 2.0);
				FOR(k, 1, j) {
					int t = s;
					t += k;
					if(t > e) break;
					if(t == e) {
						flg = true;
						rslt = i + j + k;
						break;
					}
				}
				if(flg || ans > e) break;
			}
			if(flg || ans > e) break;
		}
		cout << rslt << endl;
	}

	return 0;
}

//WA
