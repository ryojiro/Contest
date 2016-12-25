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

struct Robot {
	int cnt;
	vector<pi> num;
	char fld[10][10];
};

bool chk(int y, int x, int h, int w, char fld[10][10]) {
	if(y < 0 || x < 0 || y >= h || x >= w)
		return false;
	if(fld[y][x] == 'W' || isdigit(fld[y][x]))
		return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, w, h, l;
	cin >> n >> w >> h >> l;

	queue<Robot> q;
	set<string> s;
	pi ans;

	Robot r;
	r.num.resize(n);
	r.cnt = 0;
	char fld[10][10];
	REP(i, h) REP(j, w) {
		cin >> fld[i][j];
		if(isdigit(fld[i][j]))
			r.num[fld[i][j] - '1'] = mp(i, j);
		if(fld[i][j] == 'X')
			ans = mp(i, j);
	}
	memcpy(r.fld, fld, sizeof(fld));
	q.push(r);

	while(!q.empty()) {
		Robot r = q.front(); q.pop();
		REP(k, n) {
			REP(i, 4) {
				Robot r2 = r;
				bool flg = false;
				while(chk(r2.num[k].first + dy[i], r2.num[k].second + dx[i], h, w, r2.fld)) {
					r2.num[k].first += dy[i];
					r2.num[k].second += dx[i];
					flg = true;
				}
				if(!flg) continue;
				swap(r2.fld[r.num[k].first][r.num[k].second], r2.fld[r2.num[k].first][r2.num[k].second]);
				r2.cnt++;
				if(ans.first == r2.num[0].first && ans.second == r2.num[0].second) {
					cout << r2.cnt << endl;
					return 0;
				}
				string ss;
				REP(i, h) REP(j, w)
					ss.pb(r2.fld[i][j]);
				if(r2.cnt < l && !s.count(ss)) {
					q.push(r2);
					s.insert(ss);
				}
			}
		}
	}
	cout << "NO SOLUTION" << endl;
	return 0;
}
