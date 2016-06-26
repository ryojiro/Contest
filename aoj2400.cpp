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

bool com(const pair<int, pair<int, int> >& left, const pair<int, pair<int, int> >& right) {
	if(left.second.first == right.second.first) {
		if(left.second.second == right.second.second)
			return left.first < right.first;
		else
			return left.second.second < right.second.second;
	}
	else
		return left.second.first > right.second.first;
}

int main() {
	int T, P, R;
	while(cin >> T >> P >> R, T|P|R) {
		vector< pair<int, pair<int, int> > > vp;
		multiset<int> w;
		REP(i, T)
			vp.push_back(make_pair(i+1, make_pair(0, 0)));
		REP(j, R) {
			int tid, pid, time;
			string message;
			cin >> tid >> pid >> time >> message;
			if(message == "CORRECT") {
					vp[tid-1].second.first++;
					vp[tid-1].second.second += w.count(tid * 100 + pid) * 1200 + time;
			}
			else if(message == "WRONG")
				w.insert(tid * 100 + pid);
		}
		sort(vp.begin(), vp.end(), com);
		REP(i, vp.size())
			cout << vp[i].first << ' ' << vp[i].second.first << ' ' << vp[i].second.second << endl; 
	}
	return 0;
}
