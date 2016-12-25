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

int idx;
string s;
map<string, int> m;

int number() {
	int n = 0;
	while(isdigit(s[idx])) {
		if(n) n *= 10;
		n += s[idx++] - '0';
	}
	return n;
}

int atom() {
	string s2;
	s2 += s[idx++];
	if(islower(s[idx]))
		s2 += s[idx++];
	return m.count(s2) ? m[s2] : -1;
}

int molecute() {
	int sum = 0;
	while(idx < s.size() && s[idx] != ')') {
		if(s[idx] == '(') {
			idx++;
			int sum2 = molecute();
			if(sum2 == -1)
				return -1;
			idx++;
			sum += sum2 * number();
		}
		else {
			int sum2 = atom();
			if(sum2 == -1)
				return -1;
			if(isdigit(s[idx]))
				sum += sum2 * number();
			else
				sum += sum2;
		}
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> s, s != "END_OF_FIRST_PART") {
		int num; cin >> num;
		m[s] = num;
	}
	while(cin >> s, s != "0") {
		idx = 0;
		int ans = molecute();
		if(ans == -1)
			cout << "UNKNOWN" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
