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
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n, n) {
		int s; cin >> s;
		int a = 0, b = 0;
		bool flg = false;
		REP(i, n) {
			int a2, b2; cin >> a2 >> b2;
			a += a2, b += b2;
		}
		FOR(i, a+n, b+n+1)
			if(1 == s % i)
				flg = true;
		if(flg)
			cout << 0 << endl;
		else
			cout << 1 << endl;
	}
	return 0;
}
