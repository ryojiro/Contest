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
const int MAX = 1000000 + 1;

bool prime[MAX];

void sieve() {
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	FOR(i, 2, MAX) {
		if(prime[i]) {
			for(int j=i; j<MAX; j+=i) {
				if(j == i) continue;
				prime[j] = false;
			}
		}
	}
}

int main() {
	sieve();
	int a, d, n;
	while(cin >> a >> d >> n, a|d|n) {
		int cnt = 0;
		REP(i, MAX) {
			if(prime[a + d * i])
				cnt++;
			if(cnt == n) {
				cout << a + d * i << endl;
				break;
			}
		}
	}
	return 0;
}
