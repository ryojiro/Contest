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
#include <complex>
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

int t;
string s;
vector<vi> vvi;

void dfs(int pnt, vi v) {
	if(pnt == s.size()) {
		vvi.pb(v);
		return;
	}
	else {
		string s2 = "";
		FOR(i, pnt, s.size()) {
			vi v2 = v;
			if(i > s.size())
				break;
			s2 += s[i];
			v2.pb(stoi(s2));
			dfs(i + 1, v2);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> t, t) {
		vvi.clear();
		cin >> s;
		dfs(0, vi());
		int max = 0, pnt = -1;
		bool flg = false;
		REP(i, vvi.size()) {
			int sum = 0;
			REP(j, vvi[i].size())
				sum += vvi[i][j];
			if(sum <= t && sum > max) {
				max = sum; pnt = i;
				flg = false;
			}
			else if(sum == max)
				flg = true;
		}
		if(flg)
			cout << "rejected" << endl;
		else if(pnt == -1)
			cout << "error" << endl;
		else {
			cout << max << ' ';
			REP(i, vvi[pnt].size()) {
				if(i)
					cout << ' ';
				cout << vvi[pnt][i];
			}
			cout << endl;
		}
	}
	return 0;
}
