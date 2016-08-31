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

string s;
map<string, int> m;

int dfs(int &pnt) {
	int sum = 0;
	cout << "pnt " << pnt << endl;
	if(pnt == s.size())
		return 0;
	if(s[pnt] == '(') {
		cout << 'e' << endl;
		sum += dfs(++pnt);
	}
	if(pnt < s.size()-1 && m.count(s.substr(pnt, 2))) {
		cout << 'a' << endl;
		sum += m[s.substr(pnt, 2)];
		pnt += 2;
	}
	else if(pnt < s.size() && m.count(s.substr(pnt, 1))) {
		cout << 'b' << endl;
		sum += m[s.substr(pnt, 1)];
		pnt++;
	}
	else if(pnt < s.size() && s[pnt] == ')') {
		cout << 'c' << endl;
		pnt++;
	}
	if(pnt < s.size() && isdigit(s[pnt])) {
		cout << 'd' << endl;
		int time = 0;
		bool last  = false;
		while(pnt < s.size() && isdigit(s[pnt])) {
			time = time * 10 + s[pnt] - '0';
			pnt++;
		}
		cout << pnt << endl;
		return sum * time;
	}
	return sum += dfs(++pnt);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	bool flg = false;
	while(cin >> s) {
		if(s == "END_OF_FIRST_PART") {
			flg = true;
			continue;
		}
		if(!flg) {
			int num; cin >> num;
			m[s] = num;
		}
		if(flg) {
			int pnt = 0, ans = 0;
			while(pnt < s.size())
				ans += dfs(pnt);
			if(ans > 0)
				cout << ans << endl;
			else
				cout << "UNKNOWN" << endl;
		}
	}
	return 0;
}
