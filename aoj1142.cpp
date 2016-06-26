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
	int m;
	cin >> m;
	REP(i, m) {
		set<string> ptn;
		string input;
		cin >> input;
		FOR(j, 1, input.size()) {
			string t1 = input.substr(0, j);
			string t2 = input.substr(j);
			string t1r = input.substr(0, j);
			string t2r = input.substr(j);
			reverse(t1r.begin(), t1r.end());
			reverse(t2r.begin(), t2r.end());

			ptn.insert(t1 + t2);
			ptn.insert(t2 + t1);
			ptn.insert(t1r + t2);
			ptn.insert(t2 + t1r);
			ptn.insert(t1 + t2r);
			ptn.insert(t2r + t1);
			ptn.insert(t1r + t2r);
			ptn.insert(t2r + t1r);
		}

//		for(auto it = ptn.begin(); it != ptn.end(); it++)
//			cout << *it << endl;
		cout << ptn.size() << endl;
	}
	return 0;
}
