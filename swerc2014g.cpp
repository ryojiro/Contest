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

void shorten(vector<pi> &v, int n) {
	int cntx = 0, cnty = 0;
	REP(i, n) {
		int minx = IINF, miny = IINF;
		vi mivx, mivy;
		REP(j, n) {
			if(minx == v[j].first)
				mivx.pb(j);
			if(miny == v[j].second)
				mivy.pb(j);

			if(minx > v[j].first && v[j].first >= cntx) {
				minx = v[j].first;
				mivx.clear();
				mivx.pb(j);
			}
			if(miny > v[j].second && v[j].second >= cnty) {
				miny = v[j].second;
				mivy.clear();
				mivy.pb(j);
			}
		}
		REP(k, mivx.size())
			v[mivx[k]].first = cntx;
		REP(k, mivy.size())
			v[mivy[k]].second = cnty;
		cntx++; cnty++;
		if(!mivx.size() && !mivy.size())
			break;
	}
}

int check(vector<pi> &v, vector<pi> &v2, int n) {
	int b = 0;
	REP(i, n) {
		b = max(b, v[i].first);
		b = max(b, v[i].second);
	}
	int mx = 0;
	REP(_, 4) {
		int cnt = 0;
		REP(i, n) {
			if(v[0].first == v2[i].first && v[0].second == v2[i].second) {
				REP(k, n) {
					if(v[k].first == v2[(i+k)%n].first && v[k].second == v2[(i+k)%n].second)
						cnt++;
					else
						break;
				}
			}
		}
		mx = max(mx, cnt);
		/*
		REP(i, n)
			cout << v[i].first << ' ' << v[i].second << " |";
		cout << endl;
		REP(i, n)
			cout << v2[i].first << ' ' << v2[i].second << " |";
		cout << endl << endl;
		*/
		REP(i, n) {
			swap(v2[i].first, v2[i].second);
			v2[i].second = b - v2[i].second;
		}
	}
	return mx;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<pi> v, v2;
	int n; cin >> n;
	REP(i, n) {
		int x, y; cin >> x >> y;
		v.pb(pi(x,y));
	}
	cin >> n;
	REP(i, n) {
		int x, y; cin >> x >> y;
		v2.pb(pi(x,y));
	}
	shorten(v, n);
	shorten(v2, n);

	if(check(v, v2, n) == n)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}
