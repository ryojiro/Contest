#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iomanip>


using namespace std;

int main() {
	int n, cnt = 1;
	cin >> n;
	int s[n];
	for(int i=0; i<n; i++) {
		cin >> s[i];
		if(i > 0) {
			if(s[i] != s[i%cnt]) {
				cnt = i+1;
			}
		}
	}
	if(n % cnt == 0)cout << n / cnt << endl;
	else cout << 1 << endl;
	return 0;
}
