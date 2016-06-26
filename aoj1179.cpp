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
#include <queue>
#include <complex>
using namespace std;

int main() {
	int n, y, m, d;
	int mil=0;
	mil += 200 * 333;
	mil += 390/2 * 666;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> y >> m >> d;
		int cnt = 0;
		cnt += (y-1)/3 * 200;
		cnt += (y-(y-1)/3-1) * 390/2;
		for(int j=1; j<=m; j++) {
			if(j==m) cnt += d-1;
			else if(y%3==0)
				cnt += 20;
			else {
				if(j%2==1) cnt += 20;
				else cnt += 19;
			}
		}
	cout << mil - cnt << endl;
	}
	return 0;
}
