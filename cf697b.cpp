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
	string in; cin >> in;
	char a = in[0];
	int pnt = in.find('e');
	string b = in.substr(2, pnt-2);
	int d = stoi(in.substr(pnt+1, in.size() - pnt+1));

	if(a == '0' && d != 0) {}
	else
		cout << a;
	REP(i, b.size()) {
		if(b == "0")
			continue;
		if(i == d)
			cout << '.';
		cout << b[i];
	}
	if(d > b.size() && a != '0') {
		REP(i, d - b.size())
			cout << '0';
		if(b == "0")
			cout << '0';
	}
	cout << endl;
	return 0;
}
