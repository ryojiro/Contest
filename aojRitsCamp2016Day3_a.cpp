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

	int q[11] = {6, 5, 4, 3, 2, 7, 6, 5, 4, 3, 2};

	string input;
	cin >> input;

	int qpoint;
	int sum = 0;

	for(int i=0; i<12; i++) {
		if(input[i] == '?')
			qpoint = i;
		else if(i < 11)
			sum += ((int)input[i] - '0') * q[i];
	}

	int ans;
	bool check = false;
	int temp;
	if(qpoint == 11)
		ans = 11 - sum%11;
		if(ans > 9) ans = 0;
	else {
		for(int i=0; i<10; i++) {
			temp = 11 - (sum + i*q[qpoint])%11;
			if(temp > 9) temp = 0;
			if(temp == (int)(input[11] - '0')) {
				if(check == true) {
					cout << "MULTIPLE" << endl;
					return 0;
				}
				ans = i;
				check = true;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
