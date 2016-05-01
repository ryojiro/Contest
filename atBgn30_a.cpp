#include<iostream>

using namespace std;

int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	if((double)B/A > (double)D/C) cout << "TAKAHASHI" << endl;
	else if((double)B/A == (double)D/C) cout <<"DRAW" << endl;
	else cout << "AOKI" << endl;
	return 0;
}
