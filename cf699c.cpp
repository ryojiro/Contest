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

int a[101], ans, n;
void dfs(int pnt, int type, int cnt) {
	//0 good
	//1 gym
	//2 contest
	if(ans < cnt) return;
	if(pnt == n) {
		ans = min(ans, cnt);
		return;
	}
	if(a[pnt] == 0)
		dfs(pnt+1, 0, cnt+1);
	else if(a[pnt] == 1) {
		if(type == 2)
			dfs(pnt+1, 0, cnt+1);
		else
			dfs(pnt+1, 2, cnt);
	}
	else if(a[pnt] == 2) {
		if(type == 1)
			dfs(pnt+1, 0, cnt+1);
		else
			dfs(pnt+1, 1, cnt);
	}
	else if(a[pnt] == 3) {
		if(type == 1)
			dfs(pnt+1, 2, cnt);
		else if(type == 2)
			dfs(pnt+1, 1, cnt);
		else
			dfs(pnt+1, 0, cnt);
	}
}


int main() {
	cin >> n;
	REP(i, n)
		cin >> a[i];
	ans = INF;
	dfs(0, 0, 0);
	cout << ans << endl;
	return 0;
}
