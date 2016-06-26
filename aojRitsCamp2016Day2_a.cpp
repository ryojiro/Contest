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
	int n,m;
	cin >> n >> m;

	int count = 0;
	int input;
	int ex;
	for(int i=0; i<m; i++) {
		cin >> input;
		if(i == 0 && input-1 > count) count = input-1;
		if(i == m-1 && n-input > count) count = n-input;
		if(i != 0 && (input-ex)/2 > count) count = (input-ex)/2;
		ex=input;
	}

	cout << count << endl;

	return 0;
}
