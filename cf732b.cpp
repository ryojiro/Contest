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

	int n, k; cin >> n >> k;
	vi v(n);
	REP(i, n)
		cin >> v[i];

	int sum = 0;
	FOR(i, 1, n) {
		int con = v[i-1] + v[i];
		if(con < k) {
			sum += k - con;
			v[i] = k - v[i-1];
		}
	}
	cout << sum << endl;
	REP(i, n)
		cout << v[i] << ' ';
	cout << endl;
	return 0;
}
