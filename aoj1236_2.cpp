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
const int INF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void add_Node(int a, int b, vector<vi> &node, vi &edge) {
	node[a].pb(b);
	node[b].pb(a);
	edge[a]--;
	edge[b]--;
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	while(n--) {
		vi edge, cur;
		vector<vi> node(100);
		int in, cnt = -1, times = -1, pre;
		while(cin >> in, in) {
			if(in > 0) {
				cnt++; times++;
				edge.pb(in);
				if(times)
					add_Node(times, pre, node, edge);
				cur.pb(cnt);
				pre = times;
			}
			else if(in < 0) {
				for(int i = pre; i >= 0; i--) {
					if(cur[i] - cnt == in && edge[i] > 0) {
						add_Node(pre, i, node, edge);
						break;
					}
				}
			}
			while(!edge[pre]) pre--;
			cnt = cur[pre];
		}
		REP(i, node.size()) {
			if(node[i].empty())
				continue;
			cout << i + 1;
			sort(node[i].begin(), node[i].end());
			REP(j, node[i].size())
				cout << ' ' << node[i][j] + 1;
			cout << endl;
		}
	}
	return 0;
}
