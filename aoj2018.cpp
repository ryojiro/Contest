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
	int n, m, p;
	while(cin >> n >> m >> p, n|m|p) {
		int x[n], sum=0;
		for(int i=0; i<n; i++) {
			cin >> x[i];
			sum += x[i];
		}

		if(x[m-1]==0)
			cout << 0 << endl;
		else
			cout << sum*(100-p)/x[m-1] << endl;
	}

	return 0;
}
