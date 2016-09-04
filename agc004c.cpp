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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int h, w; cin >> h >> w;
	char a[h][w], b[h][w];
	REP(i, h) {
		REP(j, w) {
			if(i%2 == 1 || j == 0)
				a[i][j] = '#';
			else
				a[i][j] = '.';
		}
	}
	REP(i, h) {
		REP(j, w) {
			if(i%2 == 0 || j == w-1)
				b[i][j] = '#';
			else
				b[i][j] = '.';
		}
	}
	REP(i, h) {
		a[i][0] = '#';
		b[i][0] = '.';
		a[i][w-1] = '.';
		b[i][w-1] = '#';
	}
	REP(i, h) REP(j, w) {
		char in; cin >> in;
		if(in == '#')
			a[i][j] = b[i][j] = '#';
	}
	REP(i, h) {
		REP(j, w)
			cout << a[i][j];
		cout << endl;
	}
	cout << endl;
	REP(i, h) {
		REP(j, w)
			cout << b[i][j];
		cout << endl;
	}
	return 0;
}
