#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

int main() {
	long long n;
	cin >> n;

	bool is_prime[1000000];
	for(int i=0; i<n; i++) is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;
	for(int i=2; i<n; i++) {
		if(is_prime[i]) {
			for(int j=2*i; j<=n; j+=i) is_prime[j] = false;
		}
	}
	bool is_square_prime[1000000];
	for(int i=0; i<n; i++) is_square_prime[i] = true;
	is_square_prime[0] = is_square_prime[1] = false;
	for(int i=2; i<n; i++) {
		if(is_square_prime[i]) {
			for(int j=2*i*i; j<=n; j+=i*i) is_square_prime[j] = false;
		}
	}

	return 0;
}
