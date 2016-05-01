#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;


int main() {
	while(1) {
		int x, y;
		cin >> y >> x;
		if(x==0 && y==0) break;
		int field[x][y];
		for(int i=0; i<x; i++) {
			for(int j=0; j<y; j++) {
				cin >> field[i][j];
			}
		}
		int dp[x+1][y];
		for(int i=0; i<x+1; i++) {
			for(int j=0; j<y; j++) {
				dp[i][j] = 0;
			}
		}
		for(int i=0; i<x; i++) {
			for(int j=0; j<y; j++) {
				if(i==0 && field[i][j] == 0) dp[i][j] = 1;
				else {
					if(field[i][j] == 0) {
						if(0<j && field[i-1][j-1] == 0) dp[i][j] += dp[i-1][j-1];
						if(field[i-1][j] == 0) dp[i][j] += dp[i-1][j];
						if(j<y-1 && field[i-1][j+1] == 0) dp[i][j] += dp[i-1][j+1];
					}
					if(field[i][j] == 2) {
						if(field[i-1][j] == 0) dp[i][j] += dp[i-1][j];
						if(field[i+2][j] != 1) dp[i+2][j] += dp[i][j];
					}
				}
			}
		}
		for(int i=0; i<y; i++) dp[x][i] += dp[x-1][i];

		int sum=0;
		for(int i=0; i<y; i++) sum += dp[x][i];
		cout << sum << endl;

		//cout << endl;
		//for(int i=0; i<x+1; i++) {
			//for(int j=0; j<y; j++) {
				//cout << dp[i][j] << ' ';
			//}
			//cout << endl;
		//}
	}
	return 0;
}
