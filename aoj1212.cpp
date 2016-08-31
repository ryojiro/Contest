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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n, n>0) {
		bool x[9][9] = {};
		bool y[9][9] = {};
		REP(i, n) {
			char in1; int in2, in3;
			cin >> in1 >> in2 >> in3;
			if(in1 == 'x')
				x[in2][in3] = true;
			else if(in1 == 'y')
				y[in2][in3] = true;
		}
		REP(i, 9) {
			REP(j, 9)
				cout << y[i][j];
			cout << endl;
		}
	}

	return 0;
}
