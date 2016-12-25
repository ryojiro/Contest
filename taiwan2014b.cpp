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
#include <bitset>
#include <complex>
using namespace std;
#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for(int i = a; i < (int)b; i++)
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
const double EPS = 1e-8;
const double INF = 1e12;
const int MAX_V = 100;

//////////////////////////////
// UnionFind
vector<int> v, parent, depth;
int find(int a){
  if(parent[a] == a) return a;
  else return parent[a] = find(parent[a]);
}
void merge(int a, int b){
  int pa = find(a), pb = find(b);
  if(pa == pb) return ;

  if(depth[pa] > depth[pb]) swap(pa, pb);
  if(depth[pa] == depth[pb]) ++depth[pa];
  parent[pb] = pa;
}
bool same(int a, int b){
  return find(a) == find(b);
}
void init_union_find(int V){
  v = vector<int>(V);
  parent = vector<int>(V);
  depth = vector<int>(V, 1);
  REP(i, V) parent[i] = i;
}
//////////////////////////////
// クラスカル法(Unionfind必要)
struct edge {
	  int f, t, c;
		  bool operator < (const edge &e) const { return c < e.c; };
};
int kruskal(int V, int E, vector<edge> es){
	  sort(es.begin(), es.end());
		  init_union_find(V);
			  int min_cost = 0;
				  REP(i, E){
						    if(!same(es[i].f, es[i].t)){
									      min_cost += es[i].c;
												      merge(es[i].f, es[i].t);
															    }
								  }
					  return min_cost;
}

int main() {
	int n; cin >> n;
	while(n--) {
		int v, e; cin >> v >> e;
		vector<edge> ve(e);
		int sum = 0;
		REP(i, e) {
			cin >> ve[i].f >> ve[i].t >> ve[i].c;
			sum += ve[i].c;
		}
		cout << sum - kruskal(v, e, ve) << endl;
	}

	return 0;
}
