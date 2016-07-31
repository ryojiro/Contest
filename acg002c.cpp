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
	int N;
	ll L;
	cin >> N >> L;
	ll sum = 0LL;
	int a[N];
	bool flg = false;
	REP(i, N) {
		cin >> a[i];
		sum += a[i];
	}
	vi v;
	int f = 0, l = N-1;
	while(true) {
		if(a[f] < a[l]) {
			v.pb(f+1);
			sum -= (ll)a[f];
			f++;
		}
		else if(a[f] > a[l]) {
			v.pb(l);
			sum -= (ll)a[l];
			l--;
		}
		if(f == l)
			break;
		if(sum < L) {
			flg = true;
			break;
		}
	}
	if(flg)
		cout << "Impossible" << endl;
	else {
		cout << "Possible" << endl;
		REP(i, v.size())
			cout << v[i] << endl;
	}
	return 0;
}
