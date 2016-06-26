#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

int main() {
	int T, h, w;
	cin >> T;
	for(int i=0; i<T; i++) {
		cin >> h >> w;
		int bigger = (h>w)? h : w;
		if(h == w) cout << "1 0" << endl;
		else if(h == 1 || w == 1) {
			if(bigger % 2 == 0) cout << "1 1" << endl;
			else cout << bigger/2+1 << ' ' << bigger/2 << endl;
		}
		else if(h % 2 == 1 && w % 2 == 1)
			cout << h*w/2+1 << ' ' << h*w/2 << endl;
		else cout << "1 1" << endl;
	}
	return 0;
}

//cant make
