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
const int INF = 10e8 + 1;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
const int MAX_V = 201;

int V, match[MAX_V], used[MAX_V];
pi pnt[MAX_V];
vector<int> G[MAX_V];
int mx;

bool dfs(int v){
	used[v] = true;
	REP(i, G[v].size()){
		int u = G[v][i], w = match[u];
		if((w < 0 || (!used[w] && dfs(w)))) {
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}

int bipartite_matching(){
	int res = 0;
	memset(match, -1, sizeof(match));
	REP(v, V)
		if(match[v] < 0){
			memset(used, 0, sizeof(used));
			if(dfs(v)) ++res;
		}
	return res;
}

int main() {
	int X; cin >> X;
	REP(i, X*2)
		cin >> pnt[i].first >> pnt[i].second;
	V = X * 2;
	int l = 0, r = INF;
	while(r - l >= 1){
		int Y = (l + r) / 2;
		REP(i, X*2)
			G[i].clear();
		REP(i, X){
			FOR(j, X, X*2) {
				int x = abs(pnt[i].first - pnt[j].first);
				int y = abs(pnt[i].second - pnt[j].second);
				if(x + y <= Y) {
					G[i].pb(j);
					G[j].pb(i);
				}
			}
		}
		if(bipartite_matching() == X) r = Y;
		else l = Y;
		cout << r << endl;
	}
	cout << r << endl;
	return 0;
}
