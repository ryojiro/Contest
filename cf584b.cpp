#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

int main() {

	unsigned long long n;
	cin >> n;

	unsigned long long count = 1;
	for(int i=0; i<n; i++) {
		count *= 27;
		count %= 1000000007;
	}
	unsigned long long sum6 = 1;
	for(int i=0; i<n; i++) {
		sum6 *= 7;
		sum6 %= 1000000007;
	}
	if(count < sum6) count += 1000000007;

	cout << (count - sum6) << endl;
	return 0;
}
