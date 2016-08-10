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
	int n, m = 0, c = 0; cin >> n;
	REP(i, n) {
		int in1, in2; cin >> in1 >> in2;
		if(in1 > in2)
			m++;
		else if(in1 < in2)
			c++;
	}
	if(m > c)
		cout << "Mishka" << endl;
	else if(m < c)
		cout << "Chris" << endl;
	else
		cout << "Friendship is magic!^^" << endl;
	return 0;
}
