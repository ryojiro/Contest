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
const int INF = 1<<30;
const ll MOD = 1000000007;

int main() {
	int n, m; cin >> n >> m;
	int a[10001], b[10001];
	REP(i, n)
		cin >> a[i];
	REP(i, m)
		cin >> b[i];
	int r = 0;
	REP(i, n) {
		int pre = INF;
		REP(j, m) {
			if(abs(a[i] - b[j]) <= pre)
				pre = abs(a[i] - b[j]);
			else
				break;
		}
		r = max(r, pre);
	}
	cout << r << endl;
	return 0;
}
