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
#include <stack>
#include <queue>
#include <complex>
using namespace std;
#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for(int i = a; i < (int)b; i++)
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;
const int INF = 1<<28;
const ll MOD = 1000000007;

int main() {
	vector<bool> prime(1<<15, true);
	prime[0] = prime[1] = false;
	FOR(i, 2, 1<<15) {
		if(prime[i]) {
			for(int j=i*2; j < 1<<15; j += i)
				prime[j] = false;
		}
	}
	int n;
	while(cin >> n, n) {
		int cnt = 0;
		REP(i, n) {
			if(prime[i] > n)
				break;
			FOR(j, i, n) {
				if(prime[j] > n)
					break;
				if(prime[i] && prime[j] && i + j == n) {
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
