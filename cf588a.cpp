#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

int main() {
	int n;
	int a[100000], p[100000];

	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i] >> p[i];

	int min = p[0], sum = 0, bought = 0;
	for(int i=0; i<n; i++) {
		if(min > p[i]) min = p[i];
		sum += min * a[i];
	}

	cout << sum << endl;
	return 0;
}
