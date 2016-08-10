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

int main() {
	string s;
	while(getline(cin, s)) {
		string s2 = "";
		REP(i, s.size())
			if(isalpha(s[i]))
				s2.pb(toupper(s[i]));
		vector<string> vs;
		set<string> se;
		REP(i, s2.size()) {
			int cnt = 0;
			FOR(j, 1, s2.size()) {
				if(i-j < 0 || s2.size() < i+j)
					break;
				if(s2[i-j] == s2[i+j]) {
					cnt = j;
					if(cnt > 1)
						se.insert(s2.substr(i-j+1, j*2-1));
				}
				else
					break;
			}
			string s3 = s2.substr(i-cnt, cnt*2 + 1);
			if(cnt > 0  && !se.count(s3))
				vs.pb(s3);
			//2
			if(i != s2.size()-1 && s2[i] == s2[i+1]) {
				int cnt = 0;
				FOR(j, 1, s2.size()) {
					if(i-j < 0 || s2.size() < i+1+j)
						break;
					if(s2[i-j] == s2[i+1+j]) {
						cnt = j;
						if(cnt > 1)
							se.insert(s2.substr(i-j+1, j*2));
					}
					else
						break;
				}
				string s3 = s2.substr(i-cnt, cnt*2 + 2);
				if(cnt > 0  && !se.count(s3))
					vs.pb(s3);
			}
		}
		REP(i, vs.size()) {
			if(!se.count(vs[i])) {
				cout << vs[i];
				if(i != vs.size()-1)
					cout << ' ';
				se.insert(vs[i]);
			}
		}
		cout << endl;
	}
	return 0;
}
