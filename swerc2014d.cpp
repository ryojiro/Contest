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
const int MAX_V = 20000;
int V, match[MAX_V], used[MAX_V];
vi G[MAX_V];

bool dfs(int v){
	used[v] = true;
	REP(i, G[v].size()){
		int u = G[v][i], w = match[u];
		if(w < 0 || (!used[w] && dfs(w))){
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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int M; cin >> V >> M;
	V *= 2;
	REP(i, M){
		int u, v; cin >> u >> v;
		v += V/2;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(bipartite_matching() == V/2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
