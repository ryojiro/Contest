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
	string a = "AHIMOoTUVvWwXxY";
	string in; cin >> in;
	bool flg = true;
	REP(i, in.size()) {
		if(in[i] == 'b' && in[in.size() - i-1] == 'd') {}
		else if(in[i] == 'd' && in[in.size() - i-1] == 'b') {}
		else if(in[i] == 'p' && in[in.size() - i-1] == 'q') {}
		else if(in[i] == 'q' && in[in.size() - i-1] == 'p') {}
		else if(a.find(in[i]) != -1) {}
		else
			flg = false;
	}
	if(flg)
		cout << "TAK" << endl;
	else
		cout << "NIE" << endl;
	return 0;
}
