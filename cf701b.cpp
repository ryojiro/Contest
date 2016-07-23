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
	set<int> row, col;
	int rtime = 0, ctime = 0;
	int n, m; cin >> n >> m;
	ll sum = (ll)n*n;
	REP(i, m) {
		int in1, in2; cin >> in1 >> in2;
		if(!row.count(in1)) {
			sum -= n - ctime;
			rtime++;
			row.insert(in1);
		}
		if(!col.count(in2)) {
			sum -= n - rtime;
			ctime++;
			col.insert(in2);
		}
		cout << sum << ' ';
	}
	cout << endl;
	return 0;
}
