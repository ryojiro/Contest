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
	int N, M; cin >> N >> M;
	int box[100001];
	fill(box, box+100001, 1);
	bool red[100001] = {};
	red[1] = true;
	REP(i, M) {
		int x, y; cin >> x >> y;
		box[x]--; box[y]++;
		if(red[x])
			red[y] = true;
		if(!box[x])
			red[x] = false;
	}
	int cnt = 0;
	FOR(i, 1, N+1)
		if(red[i])
			cnt++;
	cout << cnt << endl;
	return 0;
}
