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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	string s; cin >> s;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
	char c[2] = {'r', 'b'};
	bool flg = false;
	REP(i, n) {
		if(i%2 == 0 && s[i] != c[0])
			cnt1++;
		else if(i%2 && s[i] != c[1])
			cnt2++;
		if(i%2 == 0 && s[i] != c[1])
			cnt3++;
		else if(i%2 && s[i] != c[0])
			cnt4++;
	}
	cout << min(max(cnt1, cnt2), max(cnt3, cnt4)) << endl;
	return 0;
}
