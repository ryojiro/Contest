#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

long calc(long current, long f[], long b[], long n) {
	long* temp = new long[n];
	for(long i=0; i<n; i++) temp[i] = f[i];
	sort(temp, temp+n);
	long count = 0;
	bool pre = false;
	for(long i=0; i<n; i++) {
		if(temp[i] != b[i]) return -2;
		if(temp[i] == temp[i+1]) pre = true;
	}
	delete[] temp;
	if(pre) return -1;
	else return current;
}

int main() {
	long m, n;
	cin >> m >> n;

	long* f = new long[m];
	long* b = new long[n];
	for(long i=0; i<m; i++) cin >> f[i];
	for(long i=0; i<n; i++) cin >> b[i];

	sort(b, b+n);
	long temp = 0;
	for(int i=0; i<m-n+1; i++) {
		temp = calc(i, f, b, n);
		if(temp == -1) {
			cout << "Ambiguity" << endl;
			break;
		}
		else if(temp >= 0) {
			cout << "Possible" << endl;
			for(int i=0; i<n; i++) cout << f[i] << ' ';
			cout << endl;
			break;
		}
	}
	if(temp == -2) cout << "Impossible" << endl;

	delete[] f;
	delete[] b;

	return 0;
}
