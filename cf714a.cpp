#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
using namespace std;
#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for(int i = a; i < (int)b; i++)
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
const int IINF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll l1, r1, l2, r2, k;
	cin >> l1 >> r1 >> l2 >> r2 >> k;
	ll l, r;
	bool flg = false;
	if(r1 < l2)
		flg = true;
	else if(l1 <= l2 && r2 <= r1) {
		l = l2; r = r2;
	}
	else if(l2 <= l1 && r1 <= r2) {
		l = l1; r = r1;
	}
	else if(l1 <= l2 && l2 <= r1) {
		l = l2; r = r1;
	}
	else if(l2 <= l1 && r2 <= r1) {
		l = l1; r = r2;
	}
	else if(l2 < r1)
		flg = true;
	else
		flg = true;

	if(flg)
		cout << 0 << endl;
	else {
		ll ans = r - l + 1;
		if(l <= k && k <= r)
			ans--;
		cout << (ans>0 ? ans : 0) << endl;
	}

	return 0;
}
