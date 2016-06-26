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
const string al = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int main() {
	int n;
	while(cin >> n, n) {
		int k[n];
		REP(i, n) cin >> k[i];
		string s; cin >> s;
		int k2[s.size()];
		REP(i, s.size()) {
			size_t p = al.find(s[i]);
			k2[i] = (int)p;
		}
//		REP(i, s.size()) cout << k[i] << ' ';
		REP(i, s.size())
			cout << al[(k2[i] - k[i%n] + 52) % 52];
		cout << endl;
	}
	return 0;
}
