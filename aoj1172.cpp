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

bool prime[123456*2+1] = {};

void era() {
	FOR(i, 2, 123456*2+1) {
		bool fst = true;
		for(int j=i; j<123456*2+1; j += i) {
			if(fst) {
				fst = false;
				continue;
			}
			prime[j] = true;
		}
	}
	return;
}

int main() {
	era();
	int n;
	while(cin >> n, n) {
		int cnt = 0;
		FOR(i, n+1, n*2+1)
			if(!prime[i]) cnt++;
		cout << cnt << endl;
	} 

	return 0;
}
