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
const int dx[] = {1, 1, 1, 0, 0, -1, -1, -1}, dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

struct S {
	char fld[5][5];
	int x, y, cnt;
};

bool can_Move(int y, int x, int n, char fld[5][5]) {
	if(x < 0 || y < 0 || n <= x || n <= y)
		return false;
	if(fld[y][x] == '.')
		return true;
	return false;
}

bool check(int y, int x, int n, char fld[5][5]) {
	if(x < 0 || y < 0 || n <= x || n <= y)
		return false;
	if(fld[y][x] == '#' || fld[y][x] == '@')
		return true;
	return false;
}

void infection(S &s, int n) {
	char fld[5][5];
	REP(i, n) REP(j, n) {
		int cnt = 0;
		REP(k, 8)
			cnt += check(i+dy[k], j+dx[k], n, s.fld);
		if(s.fld[i][j] == '#' && (cnt == 2 || cnt == 3))
			fld[i][j] = '#';
		else if(s.fld[i][j] == '.' && cnt == 3)
			fld[i][j] = '#';
		else if(s.fld[i][j] == '@')
			fld[i][j] = '@';
		else
			fld[i][j] = '.';
	}
	memcpy(s.fld, fld, sizeof(fld));
	return;
}

bool done(S &s, int n) {
	REP(i, n) REP(j, n)
		if(s.fld[i][j] == '#')
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n, n) {
		S s;
		REP(i, n) REP(j, n) {
			cin >> s.fld[i][j];
			if(s.fld[i][j] == '@') {
				s.x = j; s.y = i;
			}
		}
		s.cnt = 0;
		queue<S> q; q.push(s);
		set<string> ss;

		bool flg = false;
		while(!q.empty()) {
			s = q.front(); q.pop();
			if(done(s, n)) {
				flg = true;
				break;
			}
			REP(i, 8) {
				int y = s.y + dy[i];
				int x = s.x + dx[i];
				if(!can_Move(y, x, n, s.fld)) continue;
				S s2(s);
				swap(s2.fld[y][x], s2.fld[s2.y][s2.x]);
				s2.y = y; s2.x = x;

				infection(s2, n);
				s2.cnt++;

				string str;
				REP(j, n) REP(k, n)
					str += s2.fld[j][k];
				if(!ss.count(str)) {
					q.push(s2);
					ss.insert(str);
				}
			}
		}
		cout << (flg? s.cnt : -1) << endl;
	}
	return 0;
}
