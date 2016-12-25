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
typedef pair<ll, ll> pl;
typedef unsigned long long ull;
const ll INF = 1000000000;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

ll dijkstra(const vector< vector<pl> > &cost, int s, int t, int V, int pnt){
	priority_queue<pl, vector<pl>, greater<pl> > open;
	open.push(pl(0, s));
	ll closed[V];
	REP(i, V) closed[i] = INF;
	while(!open.empty()){
		pl tmp = open.top(); open.pop();
		ll now = tmp.second, c = tmp.first;
		if(closed[now] < c) continue;
		closed[now] = c;
		REP(i, cost[now].size()){
			ll next = cost[now][i].second, nc = cost[now][i].first;
			if(nc > pnt || c + nc >= closed[next]) continue;
			closed[next] = c + nc;
			open.push(pl(closed[next], next));
		}
	}
	REP(i, V)
		cout << i << ' ' << closed[i] << endl;
	return closed[t];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, x; cin >> n >> m >> x;
	vector< vector<pl> > vvp(n+1);
	REP(i, m) {
		int f, t, c; cin >> f >> t >> c;
		vvp[f].pb(pl(c, t));
	}

	ll mx = dijkstra(vvp, 1, n, n+1, INF);
	mx += mx * x / 100;
	cout << mx << endl;
	int l = 0, r = 100000;
	while(r - l > 1){
		int Y = (l + r) / 2;
		if(dijkstra(vvp, 1, n, n+1, Y) <= mx) r = Y;
		else l = Y;
	}
	cout << r << endl;


	return 0;
}
