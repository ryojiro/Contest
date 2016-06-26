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
	int L, N;
	cin >> L >> N;

	int value = 0;
	int weight;
	int point;
	for(int i=0; i<N; i++) {
		cin >> point >> weight;
		value += point * weight;
	}

	if(value == 0) {
		cout << '0' << endl;
		return 0;
	}

	for(int i= -L; i<L; i++) {
		if(i==0) i++;
		for(int j=1; j<50000; j++) {
			if(i*j + value == 0) {
				cout << '1' << endl << i << ' ' << j << endl;
				return 0;
			}
		}
	}
	return 0;
}

//not resolve
