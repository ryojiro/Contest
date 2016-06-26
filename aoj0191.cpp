#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

int main() {
	while(1) {
		int n, m;
		cin >> n >> m;
		if(n == 0 && m == 0) break;
		double data[n][n];
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				cin >> data[i][j];
			}
		}

		double dp[n][m];
		for(int i=0; i<n; i++)
			dp[i][0] = 1.0;

		for(int i=1; i<m; i++) {
			for(int j=0; j<n; j++) {
				double max = 0;
				for(int k=0; k<n; k++) {
					double value = dp[k][i-1] * data[k][j];
					if(value > max) max = value;
				}
				dp[j][i] = max;
			}
		}

		//for(int i=0; i<m; i++) {
			//for(int j=0; j<n; j++) {
				//cout << dp[i][j] << ' ';;
			//}
			//cout << endl;
		//}
		double ans = 0;
		for(int i=0; i<n; i++) {
			if(ans < dp[i][m-1]) ans = dp[i][m-1];
		}
		cout << fixed << setprecision(2) << ans << endl;
	}
	return 0;
}
