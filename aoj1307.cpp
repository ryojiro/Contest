#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
using namespace std;
#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); i++)
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
const int IINF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; 
	while(cin >> n, n) {
		vi d(n*(n-1)/2);
		REP(i, d.size())
			cin >> d[i];
		d.erase(unique(d.begin(), d.end()), d.end());

		REP(i, d.size())
			cout << d[i] << ' ';
		cout << endl;

		vi v;
		v.pb(d[0]);
		queue<vi> q, q2;
		q.push(v);
		while(!q.empty()) {
			v = q.front(); q.pop();
			if(v.size() == n-1) {
				v.pb(0);
				sort(v.begin(), v.end());
				q2.push(v);
				continue;
			}
			v.pb(d[v.size()]);
			q.push(v);
			v.pop_back();
			v.pb(abs(d[v.size()] - d[0]));
			q.push(v);
		}
		while(q2.size()) {
			v = q2.front(); q2.pop();
			REP(i, v.size())
				cout << v[i] << ' ';
			cout << endl;
			/*
			vi chk;
			FOR(i, 1, v.size()) REP(j, i)
				chk.pb(v[i] - v[j]);
			sort(chk.rbegin(), chk.rend());

			if(d == chk) {
				FOR(i, 1, v.size())
					cout << v[i] - v[i-1] << ' ';
				cout << endl;
			}
			*/
		}
		cout << "-----" << endl;
	}
	return 0;
}
