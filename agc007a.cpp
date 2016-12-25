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
const int INF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0}, dy[] = {0, 1};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int H, W;
	cin >> H >> W;
	bool b[10][10] = {};

	REP(i, H) REP(j, W) {
		char in; cin >> in;
		if(in == '#')
			b[i][j] = true;
	}
	if(abs(H-W) > 1) {
		cout << "Impossible" << endl;
		return 0;
	}

	bool flg = true;
	REP(i, H)
		if(!(b[i][i] && b[i][i+1]))
			flg = false;
	REP(i, H) REP(j, W) {
		if(j == i || j == i+1)
			continue;
		if(b[i][j])
			flg = false;
	}
	if(flg) {
		cout << "Possible" << endl;
		return 0;
	}

	flg = true;
	REP(i, H-1)
		if(!(b[i][i] && b[i+1][i]))
			flg = false;
	REP(i, H) REP(j, W) {
		if(j == i || j+1 == i)
			continue;
		if(b[i][j])
			flg = false;
	}
	if(flg)
		cout << "Possible" << endl;
	cout << "Impossible" << endl;

	return 0;
}
