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
const int INF = 1<<28;
const ll MOD = 1000000007;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
const double EPS = 1e-5;

//1 +x
//2 -x
//3 +y
//4 -y
int dir(pi a, pi b) {
	if(a.first == b.first) {
		if(a.second > b.second)
			return 4;
		else
			return 3;
	}
	if(a.second == b.second) {
		if(a.first > b.first)
			return 2;
		else
			return 1;
	}
	return 0;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	queue<pi> a, b;
	vector<pi> vp1, vp2;
	pi ppl1, ppl2;

	REP(i, n) {
		int in1, in2; cin >> in1 >> in2;
		if(!i) {
			ppl1 = pi(in1, in2);
			vp1.pb(pi(in1, in2));
		}
		else 
			a.push(pi(in1, in2));
	}
	cin >> n;
	REP(i, n) {
		int in1, in2; cin >> in1 >> in2;
		if(!i) {
			ppl2 = pi(in1, in2);
			vp2.pb(pi(in1, in2));
		}
		else 
			b.push(pi(in1, in2));
	}

	while(!a.empty() && !b.empty()) {
		int dis1 = abs(a.front().first - ppl1.first) + abs(a.front().second - ppl1.second);
		int dis2 = abs(b.front().first - ppl2.first) + abs(b.front().second - ppl2.second);
		if(dis1 < dis2) {
			ppl1 = a.front(); a.pop();

			int chk = dir(ppl2, b.front());
			if(chk == 1)
				ppl2.first += dis1;
			else if(chk == 2)
				ppl2.first -= dis1;
			else if(chk == 3)
				ppl2.second += dis1;
			else if(chk == 4)
				ppl2.second -= dis1;
			if(ppl2 == b.front()) b.pop();
		}
		else {
			ppl2 = b.front(); b.pop();

			int chk = dir(ppl1, a.front());
			if(chk == 1)
				ppl1.first += dis2;
			else if(chk == 2)
				ppl1.first -= dis2;
			else if(chk == 3)
				ppl1.second += dis2;
			else if(chk == 4)
				ppl1.second -= dis2;
			if(ppl1 == a.front()) a.pop();
		}
		vp1.pb(ppl1); vp2.pb(ppl2);
	}


	bool flg = true;
	double ans;
	REP(i, vp1.size()-1) {
		pi d1, d2;
		d1.first = vp1[i+1].first - vp1[i].first;
		d1.second = vp1[i+1].second - vp1[i].second;
		d2.first = vp2[i+1].first - vp2[i].first;
		d2.second = vp2[i+1].second - vp2[i].second;

		double l = 0, r = 1;
		while(true){
			double rx = abs((vp1[i].first + d1.first * r) - (vp2[i].first + d2.first * r));
			double ry = abs((vp1[i].second + d1.second * r) - (vp2[i].second + d2.second * r));
			double rres = sqrt(rx * rx + ry * ry);
			if(flg) {
				ans = rres;
				flg = false;
			}
			double lx = abs((vp1[i].first + d1.first * l) - (vp2[i].first + d2.first * l));
			double ly = abs((vp1[i].second + d1.second * l) - (vp2[i].second + d2.second * l));
			double lres = sqrt(lx * lx + ly * ly);

			double Y = (l + r) / 2;
			if(abs(rres - lres) < EPS) {
				double x = abs((vp1[i].first + d1.first * (r-l)/2) - (vp2[i].first + d2.first * (r-l)/2));
				double y = abs((vp1[i].second + d1.second * (r-l)/2) - (vp2[i].second + d2.second * (r-l)/2));
				double res = sqrt(x * x + y * y);
				ans = min(ans, res);
				break;
			}
			if(rres > lres) {
				r = Y;
			}
			else l = Y;
		}
	}
	cout << ans << endl;
	return 0;
}
