#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

int main() {
	int n, t;
	cin >> n >> t;

	if(n == 1 && t == 10) cout << -1;
	else if(t == 10) {
		for(int i=0; i<n/2; i++) cout << t;
		if(n%2 == 1) cout << 0;
	}
	else for(int i=0; i<n; i++) cout << t;

	cout << endl;

	return 0;
}
