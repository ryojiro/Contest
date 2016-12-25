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

ll ans;

void dfs(string s, ll sum) {
	FOR(i, 1, s.size()+1) {
		ll sum2 = sum;
		string s2 = s.substr(i, s.size() - i);
		string s3 = s.substr(0, i);
		sum2 += stoll(s3);
		if(s2.size())
			dfs(s2, sum2);
		else
			ans += sum2;
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s; cin >> s;
	ans = 0;

	dfs(s, 0);

	cout << ans << endl;
	return 0;
}
