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
#include <stack>
#include <queue>
#include <complex>
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

struct s {
	string name, com;
	int type, price;
};
struct c {
	int l, h, sum, cnt;
	c() {
		l = INF, h = 0, sum = 0, cnt = 0;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n, n) {
		vector<s> r(n);
		map<string, pi> ppl;
		map<string, c> co;
		REP(i, n) {
			cin >> r[i].name;
			string tmp; cin >> tmp;
			if(tmp == "BUY")
				r[i].com = 1;
			else if(tmp == "SELL")
				r[i].com = 2;
			cin >> r[i].type >> r[i].price;
			if(!ppl.count(r[i].name))
				ppl[r[i].name] = mp(0, 0);
			if(!co.count(r[i].com))
				co[r[i].com] = c();
		}
		REP(i, n) {
			int p = -1, pri;
			if(r[i].type == 1)
				pri = 0;
			else if (r[i].type == 2)
				pri = INF;
			FOR(j, i+1, n) {
				if(r[i].com == r[j].com && r[i].name != r[j].name) {
					if(r[i].type == 1) {
						if(r[j].type == 2 && r[i].price >= r[j].price && r[j].price > p) {
							p = j;
							pri = r[j].price;
						}
					}
					else if(r[i].type == 2) {
						if(r[j].type == 1 && r[i].price <= r[j].price && r[j].price < p) {
							p = j;
							pri = r[j].price;
						}
					}
				}
			}
			cout << "debug " << endl;

			int p2 = r[i].price + r[p].price /2;
			if(p == -1)
				r[i].type = 0;
			else if(r[i].type == 1) {
				ppl[r[i].name].first += p2;
				ppl[r[p].name].second += p2;
				r[i].type = r[p].type = 0;
			}
			else if(r[i].type == 2) {
				ppl[r[i].name].second += p2;
				ppl[r[p].name].first += p2;
				r[i].type = r[p].type = 0;
			}
			if(co[r[i].com].l > p2)
				co[r[i].com].l = p2;
			if(co[r[i].com].h < p2)
				co[r[i].com].h = p2;
			co[r[i].com].sum += p2;
			co[r[i].com].cnt++;
		}
		for(auto it = co.begin(); it != co.end(); it++)
			cout << it->first << ' ' << it->second.l << ' ' <<  it->second.sum/ it->second.cnt << ' ' << it->second.h;
		cout << "--" << endl;
		for(auto it = ppl.begin(); it != ppl.end(); it++)
			cout << it->first << ' ' << it->second.first << ' ' << it->second.second;
		cout << "----------" << endl;
	}
	return 0;
}
