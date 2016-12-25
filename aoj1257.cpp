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

	bool b[20000];
	fill(b, b+20000, true);
	b[0] = b[1] = false;
	REP(i, 20000) {
		if(b[i]) {
			for(int j=i*2; j<20000; j += i)
				b[j] = false;
		}
	}
	vi prime;
	REP(i, 20000)
		if(b[i]) prime.pb(i);

	int n;
	while(cin >> n, n) {
		int f = 0, l = 0, sum = 0, cnt = 0;;
		while(true) {
			if(f == prime.size() || l == prime.size())
				break;
			if(sum == n)
				cnt++;
			if(sum <= n) {
				sum += prime[f];
				f++;
			}
			else if(sum > n) {
				sum -= prime[l];
				l++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
