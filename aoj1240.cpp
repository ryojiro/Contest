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

void j(string &s) {
	s = s[s.size()-1] + s;
	s.erase(s.end()-1);
}
void c(string &s) {
	s = s + s[0];
	s.erase(s.begin());
}
void e(string &s) {
	if(s.size()%2)
		REP(i, s.size()/2)
			swap(s[i], s[s.size()/2+i+1]);
	else
		REP(i, s.size()/2)
			swap(s[i], s[s.size()/2+i]);
}
void a(string &s) {
	reverse(s.begin(), s.end());
}
void p(string &s) {
	REP(i, s.size())
		if(isdigit(s[i]))
			s[i] = s[i] == '0' ? '9' : s[i]-1;
}
void m(string &s) {
	REP(i, s.size())
		if(isdigit(s[i]))
			s[i] = s[i] == '9' ? '0' : s[i]+1;

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	REP(_, n) {
		string x, y;
		cin >> x >> y;

		reverse(x.begin(), x.end());
		REP(i, x.size()) {
			if(x[i] == 'J') j(y);
			if(x[i] == 'C') c(y);
			if(x[i] == 'E') e(y);
			if(x[i] == 'A') a(y);
			if(x[i] == 'P') p(y);
			if(x[i] == 'M') m(y);
		}
		cout << y << endl;
	}
	return 0;
}
