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
#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); i++)
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
const int IINF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int *p[10][10];
int dammy;
bool f[10];
int cnt;
int times;

void dfs(int pnt, int &n, int &ans, int a[], ll &mask) {
	if(pnt == cnt) {
		int res[10] = {};
		int sum = 0;
		REP(i, n) {
			REP(j, 10) {
				if(p[i][j] == &dammy) break;
				res[i] *= 10;
				res[i] += *p[i][j];
			}
			if(i != n-1) sum += res[i];
		}
		if(sum == res[n-1])
			ans++;
		return;
	}

	REP(i, 10) {
		if(mask>>i & 1) continue;
		if(!i && f[pnt]) continue;
		a[pnt] = i;
		mask |= 1<<i;
		dfs(pnt+1, n, ans, a, mask);
		mask &= ~(1<<i);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a[10];
	REP(i, 10) REP(j, 10)
		p[i][j] = &dammy;
	int m[100] = {};
	fill(m, m+100, -1);
	int n; cin >> n;
	REP(i, n) {
		string in; cin >> in;
		REP(j, in.size()) {
			if(m[in[j]] == -1) {
				p[i][j] = &a[cnt];
				m[in[j]] = cnt++;
			}
			else
				p[i][j] = &a[m[in[j]]];
			if(!j)
				f[m[in[j]]] = true;
		}
	}
	int ans = 0;
	ll mask = 0;
	dfs(0, n, ans, a, mask);
	cout << ans << endl;
	return 0;
}
