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
	int N, L; cin >> N >> L;
	int a[N];
	int ans = -1;
	bool flg = false;
	REP(i, N) {
		cin >> a[i];
		if(i && a[i] + a[i-1] >= L)
			ans = i;
	}
	if(ans == -1)
		cout << "Impossible" << endl;
	else {
		cout << "Possible" << endl;
		FOR(i, 1, ans)
			cout << i << endl;
		for(int i=N-1; i >= ans; i--)
			cout << i << endl;
	}
	return 0;
}
