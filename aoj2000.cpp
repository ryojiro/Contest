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
	int N;
	while(cin >> N, N) {
		int map[21][21] = {};
		for(int i=0; i<N; i++) {
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}

		int M;
		cin >> M;
		int X=10, Y=10;
		for(int i=0; i<M; i++) {
			char d;
			int l;
			cin >> d >> l;
			for(int j=0; j<l; j++) {
				if(d=='N')
					Y++;
				else if(d=='E')
					X++;
				else if(d=='S')
					Y--;
				else if(d=='W')
					X--;
				N -= map[X][Y];
				map[X][Y] = 0;
			}
		}
		if(N) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}
