#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;

int cnt;
int m, num;
int cards[7][2];

void calc(int point, int sum) {
	for(int i=0; i<=cards[point][1]; i++) {
		int temp = sum;
		temp += cards[point][0]*i;
		if(temp == num) {
			cnt++;
			return;
		}
		else {
			if(point != m-1)
				calc(point+1, temp);
		}
	}
}

int main() {
	while(1) {
		cin >> m;
		if(m==0) break;

		for(int i=0; i<m; i++)
			cin >> cards[i][0] >> cards[i][1];

		int g;
		cin >> g;
		for(int i=0; i<g; i++) {
			cnt = 0;
			cin >> num;
			calc(0, 0);
			cout << cnt << endl;
		}
	}
	return 0;
}
