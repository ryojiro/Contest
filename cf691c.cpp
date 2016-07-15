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

struct S {
	int a, b;
	bool operator < (const S &c) const {
		if(b == c.b)
			return a < c.a;
		else
			return b > c.b;
	}
};

int main() {
	int n, m;
	string max;
	cin >> n >> m;
	REP(i, n) {
		int in; cin >> in;
		max.push_back(in + '0');
	}
	vector<S> v;
	REP(i, m) {
		int in1, in2; cin >> in1 >> in2;
		S s;
		s.a = in1-1; s.b = in2-1;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	cout << endl;
	REP(i, m)
		cout << v[i].a << ' ' << v[i].b << endl;
	bool chk = false;
	REP(i, m) {
		if(chk) {
			i=0;
			chk = false;
		}
		string temp = max;
		swap(temp[v[i].a], temp[v[i].b]);
		if(max[v[i].a] < max[v[i].b]) {
			cout << max[v[i].a] << ' ' << max[v[i].b] << " ---" << endl;
			max = temp;
			chk = true;
		}
	}

	REP(i, n) {
		cout << max[i];
		if(i != n-1)
			cout << ' ';
		else
			cout << endl;
	}

	return 0;
}
