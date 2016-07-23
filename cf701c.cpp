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

int main() {
	int n; cin >> n;
	vector<char> v(n);
	map<char, int> m;
	int sum = 0, ans = INF;
	REP(i, n) {
		cin >> v[i];
		if(m.find(v[i]) == m.end()) {
			sum++;
			m[v[i]] = -1;
		}
	}
	REP(i, n) {
		bool flg = false;
		m[v[i]] = i;
		int mini = INF;
		for(auto it = m.begin(); it != m.end(); it++) {
			if(it->second == -1) {
				flg = true;
				break;
			}
			else {
				mini = min(mini, it->second);
			}
		}
		if(flg) continue;
		else
			ans = min(ans, i+1 - mini);
	}
	cout << ans << endl;
	return 0;
}
