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

bool des(string a, string b, map<string, string> &m) {
	string s = a;
	while(s != "") {
		if(s == b)
			return true;;
		s = m[s];
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	while(cin >> n >> m, n|m) {
		cin.ignore();
		vector<string> v(1000);
		map<string, string> ma;
		REP(i, n) {
			string s;
			getline(cin, s);
			int cnt = 0;
			while(s[cnt] == ' ')
				cnt++;
			s = s.substr(cnt);
			ma[s] = cnt ? v[cnt-1] : "";
			v[cnt] = s;
		}
		REP(i, m) {
			string in1, in2, in3;
			cin >> in1;
			cin >> in2 >> in2 >> in2;
			cin >> in3 >> in3;
			in3.erase(in3.end() - 1);
			bool ans = false;
			if(in2 == "child" && ma[in1] == in3)
				ans = true;
			else if(in2 == "parent" && ma[in3] == in1)
				ans = true;
			else if(in2 == "sibling" && ma[in1] == ma[in3])
				ans = true;
			else if(in2 == "descendant")
				ans = des(in1, in3, ma);
			else if(in2 == "ancestor")
				ans = des(in3, in1, ma);
			cout << (ans ? "True" : "False") << endl;
		}
		cout << endl;
	}
	return 0;
}
