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

ll result;

void dfs(int num, int deep, long sum, int n, int toy[]) {
	if(deep == 3) {
		if(result > sum)
			result = sum;
	}
	else if(deep == 2)
		dfs(n-1, deep+1, sum+(long)(toy[n-1]-toy[num])*(n-1-num), n, toy);
	else
		FOR(i, num+1, n)
			dfs(i, deep+1, sum+(long)(toy[i]-toy[num])*(i-num), n, toy);

	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		n++;
		result = 1 << 30;
		int toy[20001] = {};
		FOR(i, 1, n) cin >> toy[i];
		sort(toy, toy+n);
		FOR(i, 1, n) 
			toy[i] += toy[i-1];
		dfs(0, 0, 0, n, toy);
		cout << result << endl;
	}
	return 0;
}
