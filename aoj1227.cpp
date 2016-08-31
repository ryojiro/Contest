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
const int INF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

char to_Num(char in) {
	if(in == 'a' || in == 'b' || in == 'c')
		return '2';
	if(in == 'd' || in == 'e' || in == 'f')
		return '3';
	if(in == 'g' || in == 'h' || in == 'i')
		return '4';
	if(in == 'j' || in == 'k' || in == 'l')
		return '5';
	if(in == 'm' || in == 'n' || in == 'o')
		return '6';
	if(in == 'p' || in == 'q' || in == 'r' || in == 's')
		return '7';
	if(in == 't' || in == 'u' || in == 'v')
		return '8';
	if(in == 'w' || in == 'x' || in == 'y' || in == 'z')
		return '9';
	return -1;
}

vector< vector<string> > ans;
multimap<string, string> dic;
string in;

void dfs(int s, int cnt, vector<string> v) {
	if(s+cnt > in.size())
		return;
	dfs(s, cnt+1, v);
	if(dic.count(in.substr(s, cnt))) {
		auto range = dic.equal_range(in.substr(s, cnt));
		for(auto it = range.first; it != range.second; it++) {
			vector<string> v2(v);
			v2.pb(it->second);
			if(s+cnt == in.size())
				ans.pb(v2);
			else
				dfs(s+cnt, 1, v2);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n, n) {
		ans.clear(); dic.clear();
		REP(i, n) {
			cin >> in;
			string s;
			REP(j, in.size())
				s += to_Num(in[j]);
			dic.insert(mp(s, in));
		}

		cin >> in;
		dfs(0, 1, vector<string>());

		REP(i, ans.size()) {
			bool flg = false;
			REP(j, ans[i].size()) {
				if(flg) cout << ' ';
				flg = true;
				cout << ans[i][j];
			}
			cout << '.' << endl;
		}
		cout << "--" << endl;
	}
	return 0;
}
