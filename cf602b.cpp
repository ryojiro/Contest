#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>

using namespace std;

long n, a[100000];

void calc(long min, long max, long current, long now, long &result){
	if(a[current] < min) min = a[current];
	if(max < a[current]) max = a[current];

	if(current < n){
		if(max - min <= 1) {
			if(result <= now) result = now+1;
			calc(min, max, current+1, now+1, result);
		}
	}
}

int main() {
	long result = 0;

	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];

	for(int i=0; i<n-1; i++) {
		if(i == 0 || (a[i] != a[i-1] && a[i-1] != a[i+1])) calc(a[i], a[i], i+1, 1, result);
	}
	cout << result << endl;

	return 0;
}
