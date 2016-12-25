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
#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for(int i = a; i < (int)b; i++)
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
const int IINF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

const int MAX_V = 367;
struct edge {
	int to, cap, cost, rev;
};
int V = MAX_V;
vector<edge> G[MAX_V];
int dist[MAX_V];

void add_edge(int from, int to, int cap, int cost) {
	G[from].pb((edge){to, cap, cost, G[to].size()});
	G[to].pb((edge){from, 0, -cost, G[from].size() - 1});
}

int min_cost_flow(int s, int t, int f) {
	int res = 0;
	int prevv[MAX_V] = {}, preve[MAX_V] = {};
	while(f > 0) {
		fill(dist, dist + V, IINF);
		dist[s] = 0;
		bool update = true;
		while(update) {
			update = false;
			REP(v, V) {
				if(dist[v] == IINF) continue;
				REP(i, G[v].size()) {
					edge &e = G[v][i];
					if(e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
						dist[e.to] = dist[v] + e.cost;
						prevv[e.to] = v;
						preve[e.to] = i;
						update = true;
					}
				}
			}
		}
		if(dist[t] == IINF)
			return -1;
		int d = f;
		for(int v= t; v != s; v = prevv[v])
			d = min(d, G[prevv[v]][preve[v]].cap);
		f -= d;
		res += d * dist[t];
		for(int v= t; v != s; v = prevv[v]) {
			edge &e = G[prevv[v]][preve[v]];
			e.cap -= d;
			G[v][e.rev].cap += d;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin >> n, n) {
		REP(i, MAX_V) {
			G[i].clear();
			dist[i] = 0;
		}
		REP(i, n) {
			int a, b, c;
			cin >> a >> b >> c;
			add_edge(a-1, b, 1, -c);
		}
		REP(i, 365)
			add_edge(i, i+1, 2, 0);
		cout << -min_cost_flow(0, 365, 2) << endl;
	}
	return 0;
}
