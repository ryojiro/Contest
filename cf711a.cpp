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
const int INF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	string s[1001];
	bool flg = false;
	REP(i, n) {
		cin >> s[i];
		if(!flg && s[i][0] == 'O' && s[i][1] == 'O') {
			s[i][0] = s[i][1] = '+';
			flg = true;
		}
		if(!flg && s[i][3] == 'O' && s[i][4] == 'O') {
			s[i][3] = s[i][4] = '+';
			flg = true;
		}
	}
	if(!flg)
		cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		REP(i, n)
			cout << s[i] << endl;
	}
	return 0;
}
