#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

int main() {
  int N, M;
	cin >> N >> M;
	int dtc[N], ftg[M];
	for(int i=0; i<N; i++) {
		cin >> dtc[i];
	}
	for(int i=0; i<M; i++) {
		cin >> ftg[i];
	}

	int dp[N][M];
	int temp;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(i-1-j >= 0) dp[i][j] = 2000000000;
			else {
				temp = dtc[i] * ftg[j];
				if(0<i) dp[i][j] = temp + dp[i-1][j-1];
				else dp[i][j] = temp;
				if(0<j && dp[i][j] > dp[i][j-1]) dp[i][j] = dp[i][j-1];
			}
		}
	}

	cout << dp[N-1][M-1] << endl;
}
