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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	map<int, int> m;
	
	REP(i, n) {
		char o;
		int x;
		cin >> o >> x;
		if(o == '+')
			m[x] += 1;
		else if(o == '-') {
			m[x] -= 1;
			if(!m[x])
				m.erase(x);
		}
		else if(o == '?') {
			int ans = 0;
			for(auto obj : m) {
				ans = max(ans, (obj.first ^ x));
				cout <<"obj " << obj.first << endl;
			}
			cout << ans << endl;
		}
	}
	return 0;
}
