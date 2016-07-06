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
	int n, d;
	cin >> n >> d;
	string s[100];
	REP(i, d)
		cin >> s[i];
	bool chk[100];
	memset(chk, true, sizeof(chk));
	REP(i, d) {
		REP(j, n) {
			if(s[i][j] == '0')
				chk[i] = false;
		}
	}

	int ans = 0, cnt = 0;
	REP(i, d) {
		if(!chk[i]) cnt++;
		else cnt = 0;
		ans = ans > cnt ? ans : cnt;
	}
	cout << ans << endl;
	return 0;
}
