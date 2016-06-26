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

bool prime[200 * 1000] = {};
void pre() {
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	REP(i, 200 * 1000)
		if(prime[i])
			for(int j = i*2; j < 200 * 1000; j += i)
				prime[j] = false;
	return;
}

int main() {
	pre();
	int N, P;
	while(cin >> N >> P) {
		if(N == -1 && P == -1) break;
		vector<int> line;
		int cnt = 0;
		for(int i = N+1;; i++) {
			if(prime[i]) {
				line.push_back(i);
				cnt++;
			}
			if(cnt == P) break;
		}
		vector<int> ans;
		REP(i, line.size())
			FOR(j, i, line.size())
				ans.push_back(line[i] + line[j]);
		sort(ans.begin(), ans.end());
//		REP(i, ans.size()) cout << ans[i] << ", ";
		cout << ans[P-1] << endl; 
	}
	return 0;
}
