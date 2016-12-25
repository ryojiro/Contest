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

void dfs(int u, int prev, int *cnt, int *visited, int *prenum, int *lowest, int *parent, vector< vector<int> > &v){
	visited[u] = true;
	prenum[u] = lowest[u] = *cnt;
	REP(i, v[u].size()){
		int next = v[u][i];
		if(!visited[next]){
			parent[next] = u;
			++(*cnt);
			dfs(next, u, cnt, visited, prenum, lowest, parent, v);
			lowest[u] = min(lowest[u], lowest[next]);
		} else if(next != prev)
			lowest[u] = min(lowest[u], prenum[next]);
	}
}

vector<int> articulation_points(int V, vector< vector<int> > &v){
	int visited[V], prenum[V], lowest[V], parent[V];
	memset(visited, 0, sizeof(visited));
	parent[0] = -1;
	int tmp = 1;
	dfs(0, -1, &tmp, visited, prenum, lowest, parent, v);
	vector<int> ret;
	int cnt = 0, used[V];
	memset(used, 0, sizeof(used));
	FOR(i, 1, V){
		if(parent[i] == 0) ++cnt;
		if(parent[i] > 0 && !used[parent[i]] && prenum[parent[i]] <= lowest[i]){
			used[parent[i]] = true;
			ret.push_back(parent[i]);
		}
	}
	if(cnt >= 2) ret.push_back(0);
	return ret;
}

void dfs2(int s, int pnt, int now, int &cnt, bool b[], vector<vi> &v) {
	REP(i, v[now].size()) {
		int next = v[now][i];
		if(next == s) cnt = -IINF;
		if(next != pnt && !b[next]) {
			b[next] = true;
			dfs2(s, pnt, next, ++cnt, b, v);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n, n) {
		vector<vi> v(n);
		int s, t; cin >> s >> t;
		REP(i, t) {
			int a, b; cin >> a >> b;
			v[a-1].pb(b-1);
			v[b-1].pb(a-1);
		}
		vi res = articulation_points(n, v);

		pi ans(0, 0);
		REP(i, res.size()) {
			bool b[100] = {};
			int ma = 0;
			REP(j, v[res[i]].size()) {
				int cnt = 1;
				dfs2(s-1, res[i], v[res[i]][j], cnt, b, v);
				ma = max(ma, cnt);
				//cout << "deb " << cnt << endl;
			}
			if(ma > ans.first) {
				ans.first = ma;
				ans.second = res[i];
			}
			else if (ma == ans.first && res[i] < ans.second)
				ans.second = res[i];
			//cout << res[i] <<  ' ' << ans.first << ' ' << ans.second << endl;
		}
		cout << ans.second + 1 << endl;
	}
	return 0;
}
