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

	int x1, y1, x2, y2, x3, y3;
	int cnt = 1;
	while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
		if(x1|y1|x2|y2|x3|y3 == 0)
			break;
		pair<double, double> m1, m2;
		m1 = mp((double)(x1+x2)/2, (double)(y1+y2)/2);
		m2 = mp((double)(x1+x3)/2, (double)(y1+y3)/2);
		double d1, d2;
		d1 = (double)(y2-y1)/(x2-x1);
		d2 = (double)(y3-y1)/(x3-x1);


	}
	return 0;
}
