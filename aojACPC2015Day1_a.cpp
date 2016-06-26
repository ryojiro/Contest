#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

int main() {
	long n, cnt;
	cin >> n;

	cnt = 0;
	while(n > 0) {
		n = n/2;
		cnt++;
	}

	cout << cnt << endl;

	return 0;
}
