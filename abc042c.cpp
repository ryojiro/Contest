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
	int n, k; cin >> n >> k;
	bool b[10];
	memset(b, 0, sizeof(b));
	REP(i, k) {
		int in; cin >> in;
		b[in] = true;
	}
	while(true) {
		int chk = n;
		bool flg = false;
		while(chk > 0) {
			if(b[chk % 10]) {
				n++;
				flg = true;
				break;
			}
			chk /= 10;
		}
		if(!flg) break;
	}
	cout << n << endl;

	return 0;
}
