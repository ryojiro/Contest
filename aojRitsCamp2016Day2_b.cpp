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
	int W, H, N;
	cin >> W >> H >> N;

	int a=1, b=1;
	int input;
	int count = 0;
	for(int i=0; i<N; i++) {
		cin >> input;
		if(input) b++;
		else a++;

		if(a < W) {
			if(a==b) count++;
		}
		else if(W < a && a < W+H-1) {
			if(a==b+2) count++;
		}
		else if(W+H-1 < a) {
			if(a==b+4) count++;
		}
	}

	cout << count << endl;

	return 0;
}
