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
typedef pair<int, int> P;
const int INF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

struct S {
	int next, cost, num;
	vi path;
	S() {};
	S(int a, int b, int c) : next(a), cost(b), num(c) {};
	bool operator< (const S &a) const {
		return cost > a.cost;
	}
};

set<int> s;
int min = INF;
map<int , pi> m[10001];

void check(int a, int b, int c, int i, vector< vector<S> > &n) {
	if(m[a].count(b) && m[a][b].first < c)
		return;
	else if(m[a].count(b) && m[a][b].first > c) {
		n[a][b] = S(b, c, i);
		m[a][b].first = c;
	}
	else {
		m[a][b] = mp(c, n[a].size());
		n[a].pb(S(b, c, i));
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int P, T; cin >> P >> T;
	vector< vector<S> > n(P);
	vi v(T);
	REP(i, T) {
		int a, b, c;
		cin >> a >> b >> c;
		check(a, b, c, i, n);
		check(b, a, c, i, n);
	}
	REP(i, n.size()) {
		cout << n[i].size() << endl;
	}

	priority_queue<S> pq;
	pq.push(S(0, 0, -1));
	int closed[10001];
	fill(closed, closed+10001, INF);
	set<int> s;
	int max = INF;
	while(!pq.empty()) {
		S t = pq.top(); pq.pop();
		if(closed[t.next] < t.cost) continue;
		closed[t.next] = t.cost;
		REP(i, n[t.next].size()) {
			S t2 = n[t.next][i];
			t2.cost += t.cost;
			t2.path = t.path;
			t2.path.pb(t2.num);
			if(t2.cost > closed[t2.next]) continue;
			closed[t2.next] = t2.cost;
			if(t2.next == P-1) {
				if(max > t2.cost) {
					max = t2.cost;
					s.clear();
				}
				REP(j, t2.path.size()) {
					if(t2.path[j] == -1) continue;
					s.insert(t2.path[j]);
				}
			}
			if(max > t2.cost)
				pq.push(t2);
		}
	}
	int sum = 0;
	for(auto i: s)
		sum += v[i];

	cout << sum * 2 << endl;
	return 0;
}
