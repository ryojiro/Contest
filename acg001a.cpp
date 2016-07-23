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
#include <queue>
#include <complex>
using namespace std;
#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for(int i = a; i < (int)b; i++)
const int INF = 1<<28;

int main() {
	int N; cin >> N;
	vector<int> v(N*2);
	REP(i, N*2)
		cin >> v[i];
	sort(v.begin(), v.end());
	int sum = 0;
	for(int i=0; i<N*2; i += 2)
		sum += v[i] > v[i+1] ? v[i+1] : v[i];
	cout << sum << endl;
	return 0;
}
