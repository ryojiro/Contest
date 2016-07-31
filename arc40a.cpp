#include<iostream>

using namespace std;

int main() {
	int N;
	int Blue, Red;
	Blue = 0;
	Red = 0;;
	cin >> N;
	for(int i=0; i<N; i++) {
		string line;
		cin >> line;
		for(int j=0; j<N; j++) {
			char temp;
			temp = line.at(j);
			if(temp == 'B') Blue++;
			else if(temp == 'R') Red++;
		}
	}
	if(Red > Blue) cout << "TAKAHASHI" << endl;
	else if (Red < Blue) cout << "AOKI" << endl;
	else cout << "DRAW"  << endl;
}
