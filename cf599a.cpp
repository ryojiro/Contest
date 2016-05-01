#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>

using namespace std;

int main() {

	long d[3] = {};
	cin >> d[0] >> d[1] >> d[2];

	long result = 0;
	if(d[0]<d[1]) {

		long route[3] = {};
		route[0] = d[0]*2 + d[1]*2;
		route[1] = d[0] + d[1] + d[2];
		route[2] = d[2]*2 + d[0]*2;

		result = route[0];
		for(int i=1; i<3; i++) if(route[i] < result) result = route[i];
	}
	else {

		long route[3] = {};
		route[0] = d[0]*2 + d[1]*2;
		route[1] = d[0] + d[1] + d[2];
		route[2] = d[2]*2 + d[1]*2;

		result = route[0];
		for(int i=1; i<3; i++) if(route[i] < result) result = route[i];
	}

	cout << result << endl;
	return 0;
}
