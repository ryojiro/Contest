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
	int n5 = 0, n7 = 0;
	REP(i, 3) {
		int in; cin >> in;
		if(in == 5) n5++;
		if(in == 7) n7++;
	}
	if(n5 == 2 && n7 == 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
