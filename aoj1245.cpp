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
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
const int IINF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

struct P {
	vvi v;
	int cnt;
	vector<pi> space;
};

bool done(vvi a) {
	REP(i, 4) {
		REP(j, 7) {
			if(a[i][j] != (i+1)*10 + j+1)
				return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int n; cin >> n;
	REP(_, n) {
		set <vvi> s;
		queue<P> q;
		P p;
		p.v.resize(4);
		REP(i, 4) {
			p.v[i].resize(8);
			FOR(j, 1, 8) {
				cin >> p.v[i][j];
				if(p.v[i][j] % 10 == 1) {
					p.v[i][j] = 0;
					p.space.pb(pi(i, j));
				}
			}
		}
		p.v[0][0] = 11;
		p.v[1][0] = 21;
		p.v[2][0] = 31;
		p.v[3][0] = 41;
		p.cnt = 0;
		q.push(p);
		bool flg = false;
		while(q.size()) {
			p = q.front(); q.pop();
			if(done(p.v)) {
				flg = true;
				break;
			}
			REP(i, 4) {
				P p2(p);
				int num = p2.v[p.space[i].first][p.space[i].second-1]+1;
				if(num % 10 == 8)
					continue;
				REP(j, 4) REP(k, 8) {
					if(p2.v[j][k] == num) {
						p2.v[p2.space[i].first][p2.space[i].second] = num;
						p2.v[j][k] = 0;
						p2.space[i] = pi(j, k);
						if(!s.count(p2.v)) {
							p2.cnt++;
							q.push(p2);
							s.insert(p2.v);
						}
						break;
					}
				}
				/*
				REP(j, 4) {
					REP(k, 8)
						cout << p2.v[j][k] << ' ';
					cout << endl;
				}
				*/
			}
		}
		cout << (flg ? p.cnt : -1) << endl;
	}
	return 0;
}
