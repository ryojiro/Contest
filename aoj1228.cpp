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
const int dx[] = {1, 1, 0, -1, -1, 0}, dy[] = {0, 1, 1, 0, -1, -1};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	cin.ignore();
	REP(_, n) {
		string in1, in2;
		getline(cin, in1);
		getline(cin, in2);
		string in; getline(cin, in);
		if(in1.size() != in2.size()) {
			cout << "false" << endl;
			continue;
		}

		bool b[200][200] = {};
		pi p = mp(100, 100);
		REP(i, in1.size()) {
			p.first += dx[in1[i] - 'a'];
			p.second += dy[in1[i] - 'a'];
			b[p.first][p.second] = true;
		}

		bool flg = false;
		REP(j, 6) {
			p = mp(100, 100);
			int cnt = 0;
			REP(i, in2.size()) {
				p.first += dx[(in2[i] - 'a' + j) % 6];
				p.second += dy[(in2[i] - 'a' + j) % 6];
				if(b[p.first][p.second])
					cnt++;
				if(cnt == in2.size())
					flg = true;
			}
		}
		if(flg || !in1.size())
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}
