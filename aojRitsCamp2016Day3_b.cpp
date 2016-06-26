#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;


int N;
int num[200000];
int ans;
bool swt = true;

void calc(int check1, int check2, int point) {
	if(check1 == point+1) {
		ans = check1;
		swt = false;
		return;
	}
	if(num[check1] == num[check2]) calc(check1+1, check2+1, point);
}

int main() {
	cin >> N;
	ans = N;
	for(int i=0; i<N; i++) cin >> num[i];

	for(int i=1; i<N/2; i++) {
		if(swt) calc(0, i+1, i);
		else break;
	}

	if(N==2 && (num[0]==num[1])) {
		cout << 2 << endl;
		return 0;
	}

	if(N % ans != 0) cout << N/ans << endl;
	else cout << 1 << endl;
	return 0;
}

//not accept
