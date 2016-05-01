#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>

using namespace std;

int main() {
	int x[10], y[10], bx, by, n, m;

	cin >> n >> bx;
	for(int i=0; i<n; i++){
		cin >> x[i];
	}
	cin >> m >> by;
	for(int i=0; i<m; i++){
		cin >> y[i];
	}

	unsigned long long result[2] = {};
	for(int i=0; i<n; i++){
		result[0] += x[i] * powl(bx, n-i-1);
	}
	for(int i=0; i<m; i++){
		result[1] += y[i] * powl(by, m-i-1);
	}


	if(result[0] > result[1]) cout << '>' << endl;
	else if(result[0] < result[1]) cout << '<' << endl;
	else cout << '=' << endl;

	return 0;
}
