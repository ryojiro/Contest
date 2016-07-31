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
const ll MOD = 1000000007;

int main() {
	ll a, b; cin >> a >> b;
	int flg1 = 0, flg2 = 0;
	if(a <= 0 && 0 <= b)
		cout << "Zero" << endl;
	else {
		if(0 <= a && 0 <= b)
			cout << "Positive" << endl;
		else {
			ll c = b - a;
			if(abs(c) % 2)
				cout << "Positive" << endl;
			else
				cout << "Negative" << endl;
		}
	}
	return 0;
}
